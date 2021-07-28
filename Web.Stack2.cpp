#include <iostream>
#include <string.h>
#include "LStack.h"
#include <stdbool.h>
#include <string>

using namespace std;

void PrintDomainName(string Address) //printing Domain Name.
{
	string domain;
	domain=Address; //assaigning the Address to domain to be changed below.

	domain.replace(domain.begin(),domain.begin()+4," "); //replacing the first 4 characters with a space, since the sub-domain will include www. always 
  	int len=domain.length();//getting the length of the string after replacing the sub-domain.
    int S=len-4; //substract the length with 4 -> the top-level domain will contain 4 character for example .com ,.org etc
    domain.replace(domain.begin()+S,domain.end(),"."); //replacing the string by an end point. However domain.begin()+S means the first S letters not included in replacing
   	cout<<"You are currently visiting"<<domain<<endl;//output the domain name.
}


int main()
{
	string Cur; //String Cur shows the Current of the webAddress
	string First;// getting the first Address entered
	char choice;
	 bool FirstEntered=true;
	
	Stack<string> forward_stack ;    //creating Stacks
	Stack<string> backward_stack ;
	
	do{
			cout<<"Choose(N)ew page, go (B)ack one page, go (F)orward one page (Q)uit:"; //getting the choice from the user
        	cin>>choice;
	
	 if(choice == 'N') 
	 {        
	      	cout<<"Enter new page address: ";
	    	cin>>Cur; //saving the WebAddress into Cur
	    	PrintDomainName(Cur);//calling the function to print the domain name
	    	
	    	if(FirstEntered)  //this statment to just save the first element to First 
	    {First=Cur;
	     FirstEntered=false;}
		        	
	    		 if(!forward_stack.isEmpty()) //when adding a new WebLink we must clear the forward Stack
	        {  forward_stack.clear();
				cout<<"Forward stack is cleared."<<endl;
			}
	    	backward_stack.push(Cur);// pushing the Webaddress into the Backward Stack

	 }else if(choice == 'F')
	 { 
	    if(forward_stack.isEmpty() ) //checking if it's empty we display an error message then outputing the Current Web shown by calling the Domain function
	    {
	    	
			cerr<<"Error! There is no Forward page.\n";
			PrintDomainName(Cur);

			  }else //otherwise we go to the Forward page then pushing the Current into the BackWard Stacak 
			  {
			  
			 	 Cur=forward_stack.pop();	
				  backward_stack.push(Cur); 
				  	  
	  	      	 cout<<"You have gone to the Forward page."<<endl;
	  	      	 PrintDomainName(Cur); //prenting the domain name
 	
			 }
	 }else if(choice == 'B')
	 { 
	       	 
	 	while(Cur== backward_stack.peek() && Cur!= First ) //getting the WebAddresses transfered to the other Stack, the condion != First here to not terminate the programm when it is empty
	 	{   forward_stack.push(backward_stack.pop());}
	 	
	 		if(backward_stack.isEmpty() || Cur==First ) //if there is no back page
	      	{
	      		cerr<<"Error! There is no page before.\n";// desplaying error message then outputting the Domain name in the second line
	      		PrintDomainName(Cur);

				}
	 		 else //or showing the back visited pages if exist
		{
		 Cur=backward_stack.peek();
		 cout<<"You have gone back one page."<<endl;
		 PrintDomainName(Cur);
	   }	
}
	 }while(choice != 'Q'); // when it's Q the do while loop will stop then the last message and the end of the programm.
	 
	 cout<<"Thank you for using this simple browser. Have a nice day.";
	
}


