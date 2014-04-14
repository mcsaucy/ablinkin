Ablinkin 
========
Josh McSavaney                                                                                                                                                                                                        
Philbrick segment control hardware.
 
Architected such that a master probes for slave boards, probes for their 
column count ( max 64 columns ), and then commands the slave signs.
 
request = sent by master
reply = sent by slave
text = sending actual text data for the sign
probe = probe for sign information
update = whether the sign should reflect its new changes
column data = the bit pattern for a column
#col = Number of columns
fell off = whatever has been shifted off the sign
 
 
Packet format:
     __
    |__| <-- 0 = request, 1 = reply
    |__| <-- message type: 0 = text, 1 = probe
    |  | <-- if text and request, if the sign should update;
    |  |         if text and request, whether or not something "fell off";
    |  |         if probe, then MSB of #col
    |__| <-- if text, then MSB of column data; if probe, next bit of #col
    |__| <-- if text, next bit of column data; if probe, next bit of #col
    |__| <-- see above
    |__| <-- see above
    |__| <-- see above
        
    (The following assume a complete blank slate to start off with)
    For example, let's send a probe from the master to slave:
        M ---0b01xxxxxx--> S (trailing 6 bits don't matter for probes)
        M <--0b11110000--- S (110000 converts to 48, so S has 48 columns)
 
    Cool, now that we have that information, let's change the slave:
        M ---0b00011111--> S (shift in a bar, all turned on, don't update)
        M <--0b10000000--- S (S says nothing "fell off")
            ... We shift 47 more 11111's ...
        M ---0b00111111--> S (shift in a bar, all turned on, DO update)
        M <--0b10111111--- S (S says something DID fall off, for this
                                specific example, it's the first 11111
                                that we pushed to it)
    The perceived effect is that the display is completely blank and then,
    suddenly, the sign updates all at once. The returned values that "fell
    off" can be used to easily update signs in a sequence by taking the
    returned value and pushing it off to the next item in the segment.
