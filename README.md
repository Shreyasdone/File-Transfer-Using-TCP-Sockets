# CN_CP
<h2>Algo</h2> </br>

So basically to start coding in java we need to set up clients and one server</br></br>

<b>Client Side</b></br>
Here we will set up a server locally (later on other computer JRE)</br>
So on client side we need to create a socket object (start socket)</br>
Connect the client socket with ip address and port of the server</br>
Read the file contents in bytes using the inputDatastream </br>
Pass the content in bytes using the outputDatastream</br>
 
<b>Server Side </b></br>
Create serversocket to start connection by assigning a port</br>
Create a socket to accept connection from the client </br>
Using the inputDatastream read the received bytes of the filename and file contents</br>
Store the contents of the files received in a filename (received) on the client system (download)</br>
Close the socket connection </br>
