# TMCTF-Offensive-200
###Written by Christopher Doege


##Objective:

The offensive 200 challenge provided a code sample of a vulnerable socket server that was pulling more bytes than necessary. (Commonly occurs when those who implement a structure are unsure about what they are doing) The objective of this challenge was to

Inside of the code there are two variables, int pwned and char buffer[1024], which gives an obvious hint that pwned will be overflown into. Now we just need to figure out how.

Upon analysis of the recv invocation, we see that data is stored into the buffer, however 1028 bytes are grabbed rather than 1024. This gives us an opportunity to load 4 extra bytes into the pwned variable.

Next we examine an interesting series of checks that perform various logical operations and compares their output. We could step through each portion and try to solve the equation or we could simply brute force the 4 bytes. (Originally I used an SMT solver to solve this problem faster, however a simple while statement will suffice for those that don’t have boolector installed)

C code to brute force the logic and find the bytes necessary.

So we know that we need to send 1024 bytes of data to fill the buffer variable and we now have the data to send across to the server, however we currently have an integer, so first we have to convert this to hex. From here we have to figure out the indianess of the machine. It is generally a safe bet to assume little indian, so we can reverse the order of the bytes so that the data is sent in the correct order.

The best method to send 1024 bytes is to just send 1024 bytes of the character a.  

Now that we have the required information our exploit is almost complete. But first we have to craft a packet that will send the data across to the designated ip/port. I chose to use a simple python connection that would send the data.

After sending the data we see that we’ve gotten the flag.


TMCTF{e8eb549f48fb7}
