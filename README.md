# PA1-second-project

The task is to create a program that will analyze the transmissions of extraterrestrial civilizations.

Radio astronomers have been able to pick up messages from extraterrestrial civilizations. Finally. The messages are coming from stars that have similar characteristics to the sun. There's no doubt.

The problem is decoding the messages. Surprisingly, the encoding of all the messages is the same (extraterrestrial UNICODE), plus the same message comes from the same star over and over again. One of the questions is whether the messages will ever synchronize, i.e., whether at some point we will receive all the messages from the beginning.

The input to the program is two or more messages. Each message is entered on one line as a sequence of letters of the lowercase alphabet. Each letter specifies the length of the captured pulse: a=1, b=2, c=4, d=8, e=16, ... Next, the input contains the | character, which specifies the beginning of the message. Thus, the input in the form:

ea|babab
represents a message with pulses of length 16, 1, 2, 1, 2, 1 and 2. The total length of the message is 16 + 1 + 2 + 1 + 2 = 25 time units. The message is recorded such that there are 16+1=17 time units remaining.

In this way the program receives several messages on its input, each message may have a different length and the actual position in each message may also be different. The program will determine if and when synchronization occurs in all messages. For example, for input:

ea|babab
d|abaca
synchronization occurs in 42 units of time:
ea| bababea| = 42
d| abacad|abacad| = 42
The input to the program is the received messages in the format described above. There are at least two messages. For basic tests only two messages are input, bonus tests input more messages.

The output of the program is the computed information when the input messages are synchronized. For some inputs it may happen that the messages never synchronize, in this situation a different answer is displayed (see examples).

If the input is invalid, the program must detect this and display an error message. Display the error message on the standard output (not on the error output). Consider the following as an error:

Less than two input messages,
the message does not have the correct format (it must not be blank, it must contain only lowercase letters and just one colon character).
A demonstration of how the program works:
Corrections:
ea|babab
d|abaca
Synchronization for: 42

Corrections:
acacbbaaa|
cbbcabcabcbbaa|
Sync for: 0

Corrections:
|acabbaaa
|dcbabaaaa
Sync for: 0

Corrections:
acacbbaa|baa
bcaabaa|baaa
Sync for: 216

Corrections:
cbbcbaa|aaaa
aadaaaabaaa|abaa
Unable to reach.


Corrections:
dbdccdccbbbbaa|aaaa
bebbaedbcabbaa|ccbaa
Sync for: 276

Corrections:
jfddiaggfdffaagfacafcfbbbgdcddbfaedfeaacfeadcbabbaaa|hdccdfdbfadcdbbcbbaa
bhfdigdbgfadfdddacceaedbefeacbacaacbbbaa|cdcgebfichfbgcbjbhdfadgheifheceeehiceeedfbgcgaggfdaadacbdeccbaadbbabaa
Sync for: 5046543

Corrections:
acacbb|aaa
cbbcabcbbaa
Incorrect input.

Corrections:
acacbb|aaa
cbbc abcb|baa
Incorrect input.

