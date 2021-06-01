
#include<iostream>
#include<stdlib.h>
#include<math.h>
#include<string.h>
using namespace std;

// A simple Symmetric c++ algorithm.


int in1, in2, n, t, i, fl;
long int e[50], d[50], temp[50], j;
char en[50], m[50];
char msg[100]; // set
int prime(long int); // check if prme
void key();
long int cd(long int);
void msgencrypt();
void msgdecrypt();

int main()
{
    cout << "\nEnter Prime number\n";
    cin >> in1;

    //checking whether input is prime or not
    fl = prime(in1);
    if (fl == 0)
    {
        cout << "\nNot the correct input.\n";
        exit(0);
    }

    cout << "\nEnter another input\n";
    cin >> in2;

    fl = prime(in2);
    if (fl == 0 || in1 == in2)
    {
        cout << "\nNot the correct input.\n";
        exit(0);
    }

    cout << "\nEnter string or msg to encrypt.\n";
    cin >> msg;

    for (i = 0; msg[i] != NULL; i++)
        m[i] = msg[i];
    n = in1 * in2;
    t = (in1 - 1) * (in2 - 1);

    key();
    cout << "\Character values for E and D are:\n";

    for (i = 0; i < j - 1; i++)
        cout << "\n" << e[i] << "\t" << d[i];

    msgencrypt();
    msgdecrypt();
    return 0;
}

int prime(long int pr)// fuction check if prime
{
    int i;
    j = sqrt(pr);
    for (i = 2; i <= j; i++)
    {
        if (pr % i == 0)
            return 0;
    }
    return 1;
}

//function to generate encryption key
void key()
{
    int k;
    k = 0;
    for (i = 2; i < t; i++)
    {
        if (t % i == 0)
            continue;
        fl = prime(i);
        if (fl == 1 && i != in1 && i != in2)
        {
            e[k] = i;
            fl = cd(e[k]);
            if (fl > 0)
            {
                d[k] = fl;
                k++;
            }
            if (k == 99)
                break;
        }
    }
}

long int cd(long int a)
{
    long int k = 1;
    while (1)
    {
        k = k + t;
        if (k % a == 0)
            return(k / a);
    }
}

//function to encrypt the msg
void msgencrypt()
{
    long int pt, ct, key = e[0], k, len;
    i = 0;
    len = strlen(msg);

    while (i != len)
    {
        pt = m[i];
        pt = pt - 96;
        k = 1;
        for (j = 0; j < key; j++)
        {
            k = k * pt;
            k = k % n;
        }
        temp[i] = k;
        ct = k + 96;
        en[i] = ct;
        i++;
    }
    en[i] = -1;
    cout << "\n\nThe Encrypted message:\n";
    for (i = 0; en[i] != -1; i++)
        cout << en[i];
}


void msgdecrypt() //decrypt function
{
    long int pt, ct, key = d[0], k;
    i = 0;
    while (en[i] != -1)
    {
        ct = temp[i];
        k = 1;
        for (j = 0; j < key; j++)
        {
            k = k * ct;
            k = k % n;
        }
        pt = k + 96;
        m[i] = pt;
        i++;
    }
    m[i] = -1;
    cout << "\n\nThe decrypted message:\n";
    for (i = 0; m[i] != -1; i++)
        cout << m[i];

    cout << endl;
}