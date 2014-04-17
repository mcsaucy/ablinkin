Ablinkin
========
By: Josh McSavaney                                                                                                                                                                                                        
Philbrick segment control hardware.
 
Architected such that a master probes for slave boards, probes for their 
column count ( max 127 columns ), and then commands the slave signs. The
following reference is provided for the convenience of the developer and
anyone who will inevitably have to troubleshoot this in the future.

All bit indices are given assuming MSB.

#### Message Types:
1. text ( bit 0 = 0 ) : update the actual message contents
2. control ( bit 0 = 1 ) : query or modify sign attributes

#### Text options ( bit 0 = 0 ):
1. set update ( bit 1 = 1 ) : set the slave's update flag to either show or not show changes. In this case, this is in-lined into a text command for convenience and is very useful for making significant changes to the sign without showing those changes to the viewer until the modifications are complete
  - show changes ( bit 2 = 1 ) : show modifications to the sign's content as it is updated
  - don't show changes ( bit 2 = 0 ) : don't show modifications
2. don't set update ( bit 1 = 0 ) : don't alter the current state of the update flag
3. column data ( bits 3-7 ) : bit pattern to shift onto the sign; a slave will return a 1 in bit 1 if anything was "shifted off" the sign along with the "shifted off" data in bits 3-7. The contents of bit 2 for this scenario are undefined

#### Control options ( bit 0 = 1 ):
1. get columns ( bit 1 = 0 ) : returns the number of columns in bits 1-7 
2. set/get flags ( bit 1 = 1 ) : allows interaction with slave update, display, and erase flags. Regardless of what you flags you choose to manipulate, you will always get the current values of update, display and erase back

#### Flag manipulation options ( bit 0 = 1, bit 1 = 1 ):
1. set update ( bit 2 = 1 ) : alter the update slave's update flag
2. update flag value ( bit 3 ) : 1 causes updates to be shown immediately after every shift operation. 0 suspends updates to the sign proper while still allowing for shifting. This is useful in situations where many changes are going to be taking place and the intermediate states do not wish to be visible; simply set it to 0 before and then 1 afterwards
3. set master erase flag ( bit 4 = 1 ) : allows you to wipe the contents of the sign, respects the update flag, and then unsets the flag as there is virtually no use case to keep it on (so it will always return 0, regardless of what you set it to)
4. master erase flag value ( bit 5 ) : master erase flag value. Setting it to 1 will trigger a master reset within the slave's sign, honoring the value of the update flag when it comes to display. This is virtually no reason to set this to 0 as any time it is set to 1, it should quickly revert to 0.
5. set display flag ( bit 6 = 1 ) : set whether or not the slave actually displays anything
6. display flag value ( bit 7 ) : if this is set to 0, the slave's sign will not display anything. If set to 1, the slave's sign will display, as expected. This is useful for some effects such as blinking.

#### Return values
All commands sent to a slave will result in a response. In all cases, the message type bit ( bit 0 ) will be the same for any given command-response pair.

In cases of text, the rest of the response will contain the state of the display flag (NOT the update flag) in bit 1, followed by a bit signalling whether or not anything was shifted off the sign in bit 2. If bit 2 is 1 (data was shifted off the display), then bits 3-7 will contain the data that was shifted off. 

In cases of control messages, things are a bit different. If you request the number of columns, you get the number of columns back in bits 1-7.

If you choose to alter flags, then bits 2,4, and 6 will have what you sent to the slave. Bits 3,5, and 7 will contain the slave's values for those flags /after/ setting them. Not that certain things such as the master erase flag will be immediately set to 0 after erasing should it be set to a 1. The contents of bit 1 are undefined in this case and should be ignored.

 
``` 
Packet format:
     _
    |_| <-- 0 = text, 1 = control
    ...
    
     _
    |0| (text)
    |_| <-- 0 = don't change 
    
    |__| <-- message type: 0 = text, 1 = probe  
    |  | <-- if text and request, if the sign should update;  
    |  |         if text and request, whether or not something "fell off";  
    |  |         if probe, then MSB of #col  
    |__| <-- if text, then MSB of column data; if probe, next bit of #col  
    |__| <-- if text, next bit of column data; if probe, next bit of #col  
    |__| <-- see above  
    |__| <-- see above  
    |__| <-- see above  
```        
    (The following assume a complete blank slate to start off with)
    For example, let's send a probe from the master to slave:
```
        M ---0b01xxxxxx--> S (trailing 6 bits don't matter for probes)
        M <--0b11110000--- S (110000 converts to 48, so S has 48 columns)
```
    Cool, now that we have that information, let's change the slave:
```
        M ---0b00011111--> S (shift in a bar, all turned on, don't update)
        M <--0b10000000--- S (S says nothing "fell off")
            ... We shift 47 more 11111's ...
        M ---0b00111111--> S (shift in a bar, all turned on, DO update)  
        M <--0b10111111--- S (S says something DID fall off, for this  
                                specific example, it's the first 11111  
                                that we pushed to it)
```
    The perceived effect is that the display is completely blank and then,
    suddenly, the sign updates all at once. The returned values that "fell
    off" can be used to easily update signs in a sequence by taking the
    returned value and pushing it off to the next item in the segment.
