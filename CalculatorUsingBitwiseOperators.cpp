
//c++ program to implement a calculator using only bitwise operators

#include <iostream>


using namespace std;

int mul(int num1, int num2)
{
	   int result = 0;
	   while (num2 > 0) 
	   {
	      if (num2 & 1) 
		  {
	         result += num1;
	      }
	      num1 = num1 << 1;
	      num2 = num2 >> 1;
  		}
  		return result;
}

void calculator(int num1, int num2, int p)
{
	char choice;
	int  a, b;
	
	cout<<endl;
	cout<<"Enter + to add the numbers. "<<endl;
	cout<<"Enter - to subtract the numbers. "<<endl;
	cout<<"Enter * to multiply the numbers. "<<endl;
	cout<<"Enter / to divide the numbers. "<<endl;
	cout<<"Enter s to take square of the first number. "<<endl;
	cout<<"Enter p to evalute given power on the first number. "<<endl;
		cout<<endl;
	cin>>choice;
	

	
	if(choice=='+')
	{
	    a=num1;
	    b=num2;
	    while (num2!= 0)
	    {
	        int count=num1 & num2;
	        num1=num1^num2;
	        num2=count<<1;
	    }
	    cout<<"Sum of two numbers "<<a<<" and "<<b<<" is: "<<num1;
    }
    else if(choice=='-')
    {
	    a=num1; 
	   	b=num2;  
	
	    while (num2!= 0)
	    {
	        int count=(~num1) & num2;
	        num1=num1^num2;
	        num2=count<<1;
	    }
	    cout<<"Addition of two numbers "<<a<<" and "<<b<<" is: "<<num1;
	}
	else if(choice=='*')
	{
		a=num1; 
	   	b=num2;  
		int result = 0;
	   while (num2 > 0) 
	   {
	      if (num2 & 1) 
		  {
	         result += num1;
	      }
	      num1 = num1 << 1;
	      num2 = num2 >> 1;
  		}
  		cout<<"Multiplication of two numbers "<<a<<" and "<<b<<" is: "<<result;
	}
	else if(choice=='/')
	{
		a=num1; 
	   	b=num2;  
	   	int temp=1;
	   	int result=0;
		while(num2<=num1) 
		{
			num2<<=1;
			temp<<=1;
			}
			while(temp>1)
			{
			    num2>>=1;
			temp>>=1;
			if(num1>=num2)
			{
			    num1-=num2;
			     result+=temp;
			}
		}
			cout<<"Division of two numbers "<<a<<" and "<<b<<" is: "<<result;
	}
	else if(choice=='s')
	{
		int temp = num1;
		int square = 0;
		int count = 0;
	
		while(temp > 0)
		{
		    if((temp & 1) == 1)
		    {
		        square += num1 << count;
		    }
	
		    temp = temp >> 1;
		    count++;
		}

	cout<<"The square of the number "<<num1<<" is = "<<square<<endl;
	}
	else if(choice=='p')
	{
	    int ans = 1;
	 	int a=num1;
	    while (p > 0) 
		{
	 
	        int last_bit = (p & 1);
	 
	        // Check if current LSB
	        // is set
	        if (last_bit) 
			{
	            ans = mul(ans, num1);
	        }
	 
	        num1 = mul(num1, num1);
	 
	        // Right shift
	        p = p >> 1;
	    }
		cout<<"The calcualted power of the number "<<a<<" is = "<<ans<<endl;
	}
	
	
}

int main()
{
	int num1, num2, power;
	cout<<"Enter first number: ";
	cin>>num1;
	
	cout<<"Enter second number: ";
	cin>>num2;
	
	cout<<"Enter power to evaluate it on first number: ";
	cin>>power;
	
	calculator(num1, num2, power);
	
	return 0;
}
