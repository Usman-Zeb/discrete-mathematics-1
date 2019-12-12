#include<iostream>
#include<fstream>
#include<string>

using namespace std;

void decrypt()
{
	ifstream input;
	input.open("encrypted.txt");
	ofstream output;
	output.open("decrypted.txt");
	int k = 0;
	int shift = 0;
	char temp;
	string reference = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789 \n,.";
	
	temp = input.get();
	for (int i = 0; i < reference.length(); i++)
	{
		if (temp == reference[i])
		{
			k = i - 3;
			break;
		}
	}

	do
	{

		for (int j = 0; j < reference.length(); j++)
		{
			if (temp == reference[j])
			{
				shift = (j - k) % 66;
				if (shift < 0) shift += 66;
				temp = reference[shift];
				break;
			}
		}
		output << temp;
	} while (input.get(temp));

	input.close();
	output.close();

}

void disp_encrypted()
{
	ifstream encrypted_textfile;
	encrypted_textfile.open("encrypted.txt");
	string line = "";

	if (!encrypted_textfile)
	{
		cout << "File not found!" << endl;
	}
	else
	{
		cout << "\t\t\t\t\t\t[Encrypted Text]\n\n";
		while (!encrypted_textfile.eof())
		{
			getline(encrypted_textfile, line);
			cout << line << endl;
		}
	}
}

void disp_plain()
{
	ifstream plain_textfile;
	plain_textfile.open("decrypted.txt");

	string line = "";

	if (!plain_textfile)
	{
		cout << "File not found!" << endl;
	}
	else
	{
		cout << "\t\t\t\t\t\t[Plain Text]\n\n";
		while (!plain_textfile.eof())
		{
			getline(plain_textfile, line);
			cout << line << endl;
		}
	}

}

int main()
{
	bool flag = true;
	int selector = 0;

	do
	{
		system("CLS");
		cout << "\t\t\t\t\t============================================\n"
			<< "\t\t\t\t\t--------Cipher Shift Encryption System------\n"
			<< "\t\t\t\t\t============================================\n\n\n";

		cout << "Select from the following:\n"
			<< "1. Decrypt message\n"
			<< "2. Show encrypted message\n"
			<< "3. Show Plain text\n"
			<< "4. Exit program\n\n"
			<< "=> ";

		cin >> selector;

		switch (selector)
		{
		case 1:
			decrypt();
			break;

		case 2:
			disp_encrypted();

			break;

		case 3:
			disp_plain();

			break;

		case 4:
			flag = false;
			break;

		default:
			cout << "Invalid selection!\n";

			break;
		}

		system("PAUSE");

	} while (flag);

	return 0;
}