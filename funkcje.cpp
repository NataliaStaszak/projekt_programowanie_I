#include"header.h"
using namespace std;

//info
void Morse_info()
{
    cout<<"**********************************************************************************************************************"<<endl;
    cout<<"Morse code is a method used in telecommunication to encode text characters as standardized sequences of "<<endl;
    cout<<"dots and lines representing short and long signals, called dots and dashes, or dits and dahs."<<endl;
    cout<<"The long signal(dash) should be at least 3 times longer than the short one(dot)"<<endl;
    cout<<"Morse code is named after Samuel Morse, one of the inventors of the telegraph."<<endl;
}
void Cesar_info()
{
    cout<<"**********************************************************************************************************************"<<endl;
    cout<<"Caesar cipher is one of the simplest and most widely known encryption techniques. It is a type of monoalphabetic"<<endl;
    cout<<"substitution cipher in which each letter in the plaintext is replaced by a letter occuring selected quantity "<<endl;
    cout<<"further in the alphabet(key). The method is named after Julius Caesar, who used it in his private correspondence."<<endl;
}
void Atbash_info()
{
    cout<<"**********************************************************************************************************************"<<endl;
    cout<<"Atbash is a monoalphabetic substitution cipher witch the Hebrew orgins.The cipher works by changing the letter"<<endl;
    cout<<"lying at the distance X from the beginning of the alphabet to a letter lying at the distance X from its end"<<endl;
    cout<<"(X=key). It can be modified for use with any known writing system with a standard collating order."<<endl;
}
void RSA_info()
{
    cout<<"**********************************************************************************************************************"<<endl;
    cout<<"RSA (Rivest–Shamir–Adleman) is a public-key cryptosystem that is widely used for secure data transmission."<<endl;
	cout<<"In a public-key cryptosystem, the encryption key is public and distinct from the decryption key, "<<endl;
	cout<<"which is kept secret (private). An RSA user creates and publishes a public key based on two large prime numbers,"<<endl;
	cout<<"along with an auxiliary value. Messages can be encrypted by anyone, via the public key, but can only be decoded"<<endl;
	cout<<"by someone who knows the prime numbers. The security of RSA relies on the practical difficulty of factoring the"<<endl;
	cout<<"product of two large prime numbers."<<endl;

}
void My_own_cipher_info()
{
    cout<<"**********************************************************************************************************************"<<endl;
    cout<<"This is my own cipher created with the use of unusual Ascii MetaCharacters such as arrows and emoticons."<<endl;
    cout<<"It is simple monoalphabetic cipher in which each letter in the plaintext is replaced by a certain MetaCharacter"<<endl;
    cout<<"Its main quality is the fact that for the process of decryption access to this program is required"<<endl;
}

// funkcje pomocnicze
int check(char c)// funkcja sprawdza czy litera jest mała czy duża
{
	//jesli jest mala litera
	if( c>= 97 && c <= 122) return 0;
	//jesli jest duza litera
	if(c >= 65 && c <= 90) return 1;
	//inna niż litera
	return 2;
}

bool is_prime(int n) // funkcja sprawdza czy liczba jest pierwsza
{
    for (int i=2; i<=sqrt(n);i++)
    {
        if (n%i==0)
            return false;
    }
    return true;
}

int random_prime(int a, int b)// funkcja losuje liczbę pierwszą z podanego przedziału (a,b)
{
    int x=4;
    while (is_prime(x)==false)
    {
        mt19937 mt(random_device{}()); // generator liczb pseudolosowych
        uniform_int_distribution<int> dist(a,b);
        x =dist(mt);
    }

    return x;
}


//Pierwszy szyr - Alfabet Morse'a
void Morse()
{
    {
    string text;
    string message = "";
    string line = "|";
    char alphabet [37] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z','0','1','2','3','4','5','6','7','8','9',' '};
    string code[37] ={".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--..","-----",".----","..---","...--","....-",".....","-....","--...","---..","----."," "};


    cout << "Give text to translate: " << endl;
    getline(cin,text);
    // zamiana na duże litery
    std::transform(text.begin(), text.end(),text.begin(), ::toupper);
    for (int i=0; i<text.length(); i++)
    {
        for (int j=0; j<37; j++)
        {
            if ( text[i] == alphabet [j] )
            {
                message.append( code [j]);
                message.append(line);
            }
        }

    }

    cout<<"**********************************************************************************************************************"<<endl;
    cout << endl <<"After translation: "<< message << endl;
    cout<<"**********************************************************************************************************************"<<endl;

    }
}


// Drugi szyfr - szyfr Cezara
void Cesar()
{

	string text;
	int key;
	cout<<"Give text to translate: "<<endl;
	getline(cin,text);

	cout<<"Give key  [-26..26]: ";
	cin>>key;
	//sprawdzenie, czy klucz miesci sie w zakresie
	while(!(key >= -26 && key <= 26))
    {
        cout<<"Give key again  [-26..26]: ";
        cin>>key;
    }
	int help;
	char a, z;

	for(int i = 0; i < text.size(); i++)
	{
		help = check(text[i]);
		//ustalienie wielkosci litery
		if(help < 2)
		{
			if(help == 0)
				a = 97, z = 122;
			else
				a = 65, z = 90;

			if(key >= 0)

				if(text[i] + key <= z)
					text[i] += key;
				else
					text[i] = text[i] + key - 26;
			else
				if(text[i] + key >= a)
					text[i] += key;
				else
					text[i] = text[i] + key + 26;
		}
	}
    cout<<"**********************************************************************************************************************"<<endl;
    cout<<endl<<"After translation: "<<text<<endl;
    cout<<"**********************************************************************************************************************"<<endl;
}

//Trzeci szyfr - szyfr Atbash
void Atbash()
{
    string text;
    cout << "Give text to translate: " << endl;
    getline(cin,text);
    for(int i = 0; text[i]; i++)
    {
        if (check(text[i])==1)
        {
            text[i] = (90 - (text[i] - 65));
        }
        if(check(text[i])==0)
        {
            text[i] = (122 - (text[i] - 97));
        }
    }
    cout<<"**********************************************************************************************************************"<<endl;
    cout<<"After translation: "<<text<<endl;
    cout<<"**********************************************************************************************************************"<<endl;
}

// Czwarty szyfr - kodowanie RSA
void RSA()
{
    int a,b,e;
    string text;

    cout<<"Give the beginning of the interval (p,q): "<<endl;
    cin>>a;

    cout<<"Give the end of the interval (p,q): "<<endl;
    cin>>b;

    cout<<"Give e: "<<endl;
    cin>>e;

    cout << "Give text to translate: " << endl;
    cin >> text;


    int p= random_prime(a,b);
    int q= random_prime(a,b);
    int n = p*q;
    int c,j,ex;

    cout<<"**********************************************************************************************************************"<<endl;
    cout<<"After translation: ";

    for (int i=0; i<text.length(); i++)
    {
        c=text[i];
        j=text[i];
        ex=1;
        while(ex<e)
        {
            c=(c*j)%n;
            ex++;
        }
        cout<<c<<", ";
    }
    cout<<endl;
    double k=((p-1)*(q-1)+1)/e;
    cout<<"public key: "<<n<<" "<<e<<endl;
    cout<<"private key: "<<k<<endl;
    cout<<"**********************************************************************************************************************"<<endl;
}

// Piąty szyfr - podstawieniowy z wykorzystaniem tablicy ASCII
void My_own_cipher()
{

    string text;
    char alphabet [26] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
    char code[26] ={1,26,15,28,3,31,20,16,24,30,6,18,23,2,12,22,27,4,25,5,29,11,14,17,21,19};

    cout << "Give text to translate: " << endl;
    getline(cin,text);
    // zamiana na duże litery
    std::transform(text.begin(), text.end(),text.begin(), ::toupper);

    cout<<"**********************************************************************************************************************"<<endl;
    cout <<"After translation: ";
    for (int i=0; i<text.length(); i++)
    {
        for (int j=0; j<=26; j++)
        {
            if ( text[i] == alphabet [j] )
            {
                cout<<code[j];
            }
        }

    }

    cout<<endl<<"**********************************************************************************************************************"<<endl;
}
