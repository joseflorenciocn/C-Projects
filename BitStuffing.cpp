#include <iostream>
#include <string>


using namespace std;


int main()
{
	char word[16] = "011111101111110";
	char word_temp1[16], word_temp2[16], word_temp3[16];
	char word_bit[18];
	char word3[24];
	char flag_bit[9] = "01111110";
	int count = 0, flag = 0;
	int bit1[3] = {0};
	char word_final[33];

	//Search how many stuffing and their positions

	for (int i = 0; i < 16; i++)
	{
		if (word[i] == '1')
		{

			count++;

			if (count == 5)
			{
				bit1[flag] = i;
				flag++;
				count = 0;	
			}
		}

		else count = 0;

		
	}
	
	//Start Stuffing with 0

	if (bit1[0] == 0)
	{
		strcpy(word_temp1, word);
	}

	else
	{
		for (int x = 0; x < (bit1[0] + 1); x++)
		{
			word_temp1[x] = word[x];
		}

		word_temp1[bit1[0] + 1] = '\0';

		if (bit1[1] == 0)
		{
			for (int y = 0; y < 15 - bit1[0]; y++)
			{
				word_temp2[y] = word[bit1[0] + 1 + y];
			}

			word_temp2[15 - bit1[0]] = '\0';
		}

		else
		{
			for (int z = 0; z < (bit1[1] - bit1[0]); z++)
			{
				word_temp2[z] = word[bit1[0] + 1 + z];
			}

			word_temp2[bit1[1] - bit1[0]] = '\0';

			if (bit1[2] == 0)
			{
				for (int a = 0; a < 15 - bit1[1]; a++)
				{
					word_temp3[a] = word[bit1[1] + 1 + a];
				}

				word_temp3[15 - bit1[1]] = '\0';
			}

			else
			{
				for (int b = 0; b < (15 - bit1[1]); b++)
				{
					word_temp3[b] = word[bit1[1] + 1 + b];
				}

				word_temp3[bit1[2]+1] = '\0';
			}
		}

	}

	//Mounting the word after stuffing

	if (flag == 0)
	{
		strcpy(word_bit, word);
	}

	if (flag == 1)
	{
		strcpy(word_bit, word_temp1);
		strcat(word_bit, "0");
		strcat(word_bit, word_temp2);
	}

	if (flag == 2)
	{
		strcpy(word_bit, word_temp1);
		strcat(word_bit, "0");
		strcat(word_bit, word_temp2);
		strcat(word_bit, "0");
		strcat(word_bit, word_temp3);
	}

	if (flag == 3)
	{
		strcpy(word_bit, word_temp1);
		strcat(word_bit, "0");
		strcat(word_bit, word_temp2);
		strcat(word_bit, "0");
		strcat(word_bit, word_temp3);
		strcat(word_bit, "0");
	}

	strcpy(word_final, flag_bit);
	strcat(word_final, word_bit);
	strcat(word_final, flag_bit);

	cout << "---------- BIT STUFFING ----------" << endl << endl;
	cout <<"Before Stuffing: " << word << " -- 15 characters" << endl;
	cout <<"After Stuffing: " << word_bit << " -- " << (15+flag) << " characters" << endl;
	cout << "After framing: " << word_final << " -- " << (31 + flag) << " characters" << endl;

			return 0;
		
	}