#include <iostream>
#include <queue>
#include <cstdio>
#include <malloc.h>
#include <cstring>

using namespace std;

struct charfreq{
    char ch;
    int freq;
    charfreq *left;
    charfreq *right;
};

struct compare_c{
bool operator()(charfreq a,charfreq b)
{
    if(b.freq>a.freq)
        return true;
    else if(a.freq==b.freq && b.ch>a.ch)
        return true;
    else return false;
}
};

charfreq *extractMin(priority_queue<charfreq, vector<charfreq>,compare_c> freqset)
{
    charfreq *temp=(charfreq *)malloc(sizeof(charfreq));
    charfreq copyfrom=freqset.top();
    temp->ch=copyfrom.ch;
    temp->freq=copyfrom.freq;
    temp->left=copyfrom.left;
    temp->right=copyfrom.right;

    return temp;
}

void traverse(charfreq* root,char code[],int pos, char finalcodes[26][50])
{
    if(!root) return;
    if(root->left)
    {
        code[pos]='0';
        traverse(root->left,code,pos+1,finalcodes);
    }
    if(root->right)
    {
        code[pos]='1';
        traverse(root->right,code,pos+1,finalcodes);
    }
    if(root->ch!='#')
    {
        int i,j=0;
        for(i=0;i<pos;i++)
            finalcodes[root->ch-'a'][i]=code[i];
        finalcodes[root->ch-'a'][i]='\0';
    }
}

string decode(charfreq* root,string s)
{
    charfreq *ptr;
    string out="";
    int len=s.length(),i;
    int gotlast=1;
    //cout<<len;

    for(i=0;i<len;i++)
        {
        if(gotlast==1)
            {
            ptr=root;
            gotlast=0;
        }
        if(s[i]=='0')
            ptr=ptr->left;
        else
            ptr=ptr->right;
        if(ptr->ch=='#')
            continue;
        else
            {
            out+=ptr->ch;
            gotlast=1;
            }

    }
    return out;
}

int main(int argc,char *argv[])
{
    int t;
    cin>>t;
    while(t--)
    {
        int i,n=0;
        char finalcodes[26][50];
        string str;
        int freqs[26],charcount=0;
        char ch;
        memset(freqs,-1,sizeof(freqs));
        cin>>charcount;
        for(i=0;i<charcount;i++)
        {
            cin>>ch;
            cin>>freqs[ch-'a'];
        }
        cin>>str;

        charfreq freqel;
        priority_queue<charfreq, vector<charfreq>,compare_c> freqset;

        for(i=0;i<26;i++)
        {

            if(freqs[i]>=0)
            {

                freqel.ch=i+'a';
                freqel.freq=freqs[i]+1;
                freqel.left=NULL;
                freqel.right=NULL;
                freqset.push(freqel);
            }

        }


    charfreq top,*left,*right;
        while(freqset.size()!=1)
        {
            right=extractMin(freqset);
            freqset.pop();
            left=extractMin(freqset);
            freqset.pop();
            top.freq=left->freq+right->freq;
            top.ch='#';
            top.left=left;
            top.right=right;
            freqset.push(top);
        }

        char codearr[50];
        charfreq root=freqset.top();
        traverse(&root,codearr,0,finalcodes);

        cout<<decode(&root,str)<<'\n';
    }
    return 0;
}