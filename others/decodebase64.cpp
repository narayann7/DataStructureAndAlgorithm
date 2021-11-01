// C++ Program to decode a base64 
// Encoded string back to ASCII string 
#include <bits/stdc++.h> 
using namespace std; 
#define SIZE 100 

/* char_set = "ABCDEFGHIJKLMNOPQRSTUVWXYZ 
abcdefghijklmnopqrstuvwxyz0123456789+/" */
char* base64Decoder(string encoded, int len_str) 
{ 
	char* decoded_string; 

	decoded_string = (char*)malloc(sizeof(char) * SIZE); 

	int i, j, k = 0; 

	// stores the bitstream. 
	int num = 0; 

	// count_bits stores current 
	// number of bits in num. 
	int count_bits = 0; 

	// selects 4 characters from 
	// encoded string at a time. 
	// find the position of each encoded 
	// character in char_set and stores in num. 
	for (i = 0; i < len_str; i += 4) 
	{ 
		num = 0, count_bits = 0; 
		for (j = 0; j < 4; j++) 
		{ 
			
			// make space for 6 bits. 
			if (encoded[i + j] != '=') 
			{ 
				num = num << 6; 
				count_bits += 6; 
			} 

			/* Finding the position of each encoded 
			character in char_set 
			and storing in "num", use OR 
			'|' operator to store bits.*/

			// encoded[i + j] = 'E', 'E' - 'A' = 5 
			// 'E' has 5th position in char_set. 
			if (encoded[i + j] >= 'A' && encoded[i + j] <= 'Z') 
				num = num | (encoded[i + j] - 'A'); 

			// encoded[i + j] = 'e', 'e' - 'a' = 5, 
			// 5 + 26 = 31, 'e' has 31st position in char_set. 
			else if (encoded[i + j] >= 'a' && encoded[i + j] <= 'z') 
				num = num | (encoded[i + j] - 'a' + 26); 

			// encoded[i + j] = '8', '8' - '0' = 8 
			// 8 + 52 = 60, '8' has 60th position in char_set. 
			else if (encoded[i + j] >= '0' && encoded[i + j] <= '9') 
				num = num | (encoded[i + j] - '0' + 52); 

			// '+' occurs in 62nd position in char_set. 
			else if (encoded[i + j] == '+') 
				num = num | 62; 

			// '/' occurs in 63rd position in char_set. 
			else if (encoded[i + j] == '/') 
				num = num | 63; 

			// ( str[i + j] == '=' ) remove 2 bits 
			// to delete appended bits during encoding. 
			else { 
				num = num >> 2; 
				count_bits -= 2; 
			} 
		} 

		while (count_bits != 0) 
		{ 
			count_bits -= 8; 

			// 255 in binary is 11111111 
			decoded_string[k++] = (num >> count_bits) & 255; 
		} 
	} 

	// place NULL character to mark end of string. 
	decoded_string[k] = '\0'; 

	return decoded_string; 
} 

// Driver code 
int main() 
{ 
	cout<<"enter the string"<<endl;
string s;
cin>>s;





	// Do not count last NULL character. 


	cout <<"Encoded string : " << 
			s << endl; 
	cout <<"Decoded string : " << 
			base64Decoder(s, s.length()) << endl; 

	return 0; 
} 

