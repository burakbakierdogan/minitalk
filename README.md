# minitalk
The purpose of this project is to code a small data exchange program using UNIX signals.
With the make command, server and client executables files will be ready to be executed. 

Open 2 seperate terminals. 
In one of them, run ./server and copy the printed pid number in the terminal.
In the other one, run ./client and enter pid number as an argument along with the message you would like to send to the server.
The server will print the message in its terminal. 
The aim of this project is sending Unix signals between processes. 
I convert signals to the strings.

CLIENT.C
This program generates and sends a signal to a process. When run, it takes as its first argument a process ID and as its second argument a string. The program converts the string into an array and sends each element of the array as a signal. The signals can be of two different types: SIGUSR1 and SIGUSR2. These signals are user-defined signals and have no special meaning; however, they can be used for any desired operation by the program.

At the beginning, the program includes the library files it needs in the #include section. Then, it defines a function called ft_isspace. This function takes a character and checks if it is a white space character. If the character is a white space character, the function returns a value of 1. Otherwise, it returns a value of 0.

Then, it defines a function called ft_atoi. This function takes a string that represents an integer in a regular form and extracts and returns the integer value from the beginning of the string.

Next, it defines a function called ft_convert. This function takes an integer and converts it to binary. The binary value is written to a character array. This function also takes an index value that shows which index of the character array to use.
Then, it defines a Finally, the main function is defined. This function is the main entry point of the program and runs the rest of the program when run. The main function takes as input the number of arguments passed when run and an array of the arguments. If two arguments are passed when run (ac == 3), the program has received a process ID and a string. The ID is converted to an integer using the ft_atoi function and the string is allocated memory using the malloc function. Then, the main loop iterates through each character in the string and converts it to binary using the ft_convert function. The main loop also keeps track of the current index in the character array. After the main loop finishes, the ft_convert function is called one more time to convert the value 255 to binary and append it to the end of the character array. Finally, the ft_send_signal function is called to send the signals represented by the character array to the process with the given ID. The program ends by freeing the allocated memory and returning 0.

SERVER.C 
This program listens for signals and processes them. When run, it sets up two signal handlers, one for SIGUSR1 and one for SIGUSR2. These signal handlers are called ft_handler and are responsible for processing the signals received.

The program starts by including the necessary library files in the #include section. Then, it defines a function called ft_putnubr. This function takes an integer and writes it to standard output (stdout). It does this by recursively dividing the integer by 10 and writing the remainder to stdout.

Next, it defines the ft_handler function. This function takes an integer as input, which represents the signal number that was received. The function has two static variables, c and base. c is used to store the current value being processed and base is used as a base value to determine the place value of each signal received. If the signal received is SIGUSR1, the value of c is increased by base. If the signal received is SIGUSR2, the value of base is halved but the value of c remains unchanged. If the value of base becomes 0, it means that all signals for the current value have been received and it is time to process the value of c. If the value of c is 255, it means that the end of the message has been reached and c is reset to 0. If c is any other value, it is written to stdout and c is reset to 0.

Finally, the main function is defined. This function sets up the signal handlers for SIGUSR1 and SIGUSR2 using the signal function. It also initializes the pid variable to 0. In the main loop, if pid is 0, it gets the process ID using the getpid function and writes it to stdout. Then, the program waits for a signal to be received using the pause function. When a signal is received, the corresponding signal handler is called and the program continues processing. This loop continues indefinitely.

To use these programs, the server program must be run first. It will print out its process ID, which can then be used as the first argument when running the client program. The second argument of the client program is the string to be sent to the server. The client program will convert the string to binary and send it to the server as a series of signals. The server program will listen for these signals and convert them back into the original string, printing it out to stdout.

For example, to send the string "Hello, World!" from the client to the server, the following could be done:

Run the server program in a terminal window:
./server

Note the process ID printed by the server program.

Run the client program in a separate terminal window, using the process ID of the server as the first argument and the string to be sent as the second argument:

./client 12345 "Hello, World!"

The server program will receive the signals from the client and print out the original string:
Hello, World!

This is a simple example of how the client and server programs can be used to send and receive signals between processes. The specific implementation of the signal processing and conversion functions can be modified as needed for different applications.

**************TURKCE**********
CLIENT.C
Bu program, bir sinyal olu??turup bir i??leme g??nderir. Program ??al????t??r??ld??????nda, ilk arg??man olarak bir i??lem (process) ID'si ve ikinci arg??man olarak bir metin al??r. Program, metni bir diziye d??n????t??r??r ve dizinin her eleman??n?? bir sinyal olarak g??nderir. Sinyaller, iki farkl?? t??rden olabilir: SIGUSR1 ve SIGUSR2. Bu sinyaller, kullan??c?? taraf??ndan tan??mlanm???? sinyallerdir ve ??zel bir anlam?? yoktur; ancak, program taraf??ndan istenilen i??lemler i??in kullan??labilirler.

Program, ba??lang????ta #include b??l??m??nde ihtiya?? duydu??u k??t??phane dosyalar??n?? dahil eder. Daha sonra, ft_isspace ad??nda bir fonksiyon tan??mlan??r. Bu fonksiyon, bir karakter al??r ve karakterin bir bo??luk karakteri olup olmad??????n?? kontrol eder. E??er karakter bir bo??luk karakteriyse, fonksiyon 1 de??erini d??nd??r??r. Aksi halde, 0 de??erini d??nd??r??r.

Sonra, ft_atoi adl?? bir fonksiyon tan??mlan??r. Bu fonksiyon, bir d??zenli tamsay?? de??eri d??nd??recek ??ekilde bir karakter dizisi (string) al??r. Fonksiyon, dizinin ilk eleman??ndan ba??layarak say?? de??erini ????kart??r ve d??nd??r??r.

Daha sonra, ft_convert adl?? bir fonksiyon tan??mlan??r. Bu fonksiyon, bir tamsay?? al??r ve bu tamsay??y?? ikilik sistemine ??evirir. ??kilik sistemdeki de??er, bir karakter dizisine yaz??l??r. Bu fonksiyon ayr??ca, karakter dizisinin hangi indeksinin kullan??laca????n?? g??steren bir indeks de??eri al??r.

Sonra, ft_send_signal adl?? bir fonksiyon tan??mlan??r. Bu fonksiyon, bir karakter dizisi, bir indeks de??eri ve bir i??lem ID'si al??r. Fonksiyon, dizinin her eleman??n?? s??rayla i??leme g??nderir. E??er eleman '1' ise, SIGUSR1 sinyali g??nderilir.
E??er eleman '0' ise, SIGUSR2 sinyali g??nderilir. Bu sinyaller, kill fonksiyonu kullan??larak g??nderilir.

Son olarak, main fonksiyonu tan??mlan??r. Bu fonksiyon, program??n ana girdi noktas??d??r ve ??al????t??r??ld??????nda program??n geri kalan??n?? ??al????t??r??r. main fonksiyonu, ??al????t??r??ld??????nda ka?? tane arg??man al??nd??????n?? g??steren bir say?? ve arg??manlar??n dizisi al??r. E??er ??al????t??r??ld??????nda iki arg??man al??nd??ysa (ac == 3), program bir i??lem ID'si ve bir metin alm????t??r. Bu ID, ft_atoi fonksiyonu kullan??larak tamsay?? de??erine d??n????t??r??l??r. Daha sonra, bir karakter dizisi olu??turulur ve metin, ft_convert fonksiyonu kullan??larak bu diziye d??n????t??r??l??r. Daha sonra, ft_send_signal fonksiyonu kullan??larak bu dizi, i??lem ID'sine g??nderilir. Program sonland??r??ld??ktan sonra, olu??turulan dizi haf??zadan silinir ve program sonland??r??l??r.

SERVER.C
Bu program, bir i??lem (process) ID'si ve bu ID'ye ait olan sinyalleri al??r. Program, sinyalleri al??r ve bu sinyallerin bir diziye nas??l d??n????t??r??lece??ini g??sterir. Sinyaller, iki farkl?? t??rden olabilir: SIGUSR1 ve SIGUSR2. Bu sinyaller, kullan??c?? taraf??ndan tan??mlanm???? sinyallerdir ve ??zel bir anlam?? yoktur; ancak, program taraf??ndan istenilen i??lemler i??in kullan??labilirler.
Program, ba??lang????ta #include b??l??m??nde ihtiya?? duydu??u k??t??phane dosyalar??n?? dahil eder. Daha sonra, ft_putnubr ad??nda bir fonksiyon tan??mlan??r. Bu fonksiyon, bir tamsay?? de??er al??r ve bu de??eri ekrana yazd??r??r. Fonksiyon, tamsay??y?? rakamlar??na ay??rarak yazd??r??r. ??rne??in, de??er 123 ise, fonksiyon 1, 2 ve 3 rakamlar??n?? ekrana yazd??r??r.

Sonra, ft_handler adl?? bir fonksiyon tan??mlan??r. Bu fonksiyon, bir sinyal numaras?? al??r ve bu sinyal numaras??na g??re i??lem yapar. E??er sinyal numaras?? SIGUSR1 ise, fonksiyon bir saya?? de??i??kenini artt??r??r ve bir taban de??i??kenini yar??ya d??????r??r. E??er sinyal numaras?? SIGUSR2 ise, fonksiyon sadece taban de??i??kenini yar??ya d??????r??r. E??er taban de??i??keni s??f??ra e??itse, fonksiyon saya?? de??i??kenini ekrana yazd??r??r ve saya?? ve taban de??i??kenlerini s??f??rlar.

Son olarak, main fonksiyonu tan??mlan??r. Bu fonksiyon, program??n ana girdi noktas??d??r ve ??al????t??r??ld??????nda program??n geri kalan??n?? ??al????t??r??r. main fonksiyonu, ??al????t??r??ld??????nda hi??bir arg??man almaz. Fonksiyon, signal fonksiyonu kullan??larak SIGUSR1 ve SIGUSR2 sinyallerine ft_handler fonksiyonunu atar. Daha sonra, bir d??ng?? olu??turulur ve bu d??ng?? s??rekli olarak ??al??????r. E??er i??lem ID'si (pid) s??f??ra e??itse, ID'nin de??eri getpid fonksiyonu kullan??larak al??n??r ve ID, ft_putnubr fonksiyonu kullan??larak ekrana yazd??r??l??r. Daha sonra, program pause fonksiyonu ile bekletilir ve bekleme s??ras??nda bir sinyal al??n??rsa, ft_handler fonksiyonu ??a??r??l??r ve i??leme devam edilir. Bu ??ekilde, program s??rekli olarak sinyalleri al??r ve bu sinyalleri i??ler.
