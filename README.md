# FractionToBinaryConverter
Tiny qt tool to compute a fraction part of a number to its represented value which could be written into a register, for a micro controller for example

I used it to compute the fraction par of a number to the binary value to write it to a regsiter of a controller. 
The format of the 24 Bit register was |2^-1|2^-2|2^-3 ....|2^-23|2^-24|. I solved the problem/recalculation by writing this tiny tool in Qt.

![alt tag] (fraction_preview.png "Picture to show usage")
The image shows how to use the tool. Simply edit the number in a 0.xxx or 0,xxx fashion. Check the bit accuracy and press calculate and that's it. See the example picture to see how error is changing when reducing the bit count.

-Nils
