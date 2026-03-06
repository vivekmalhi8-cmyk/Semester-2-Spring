#include<iostream>
using namespace std;
class Message{
private:
    string text;
public:
    void setText(string t)
    {
        text = t;
    }
    string toString() const
    {
        return text;
    }
};
class SMS : public Message{
private:
    string recipientContactNo;
public:
    void setRecipient(string r)
    {
        recipientContactNo = r;
    }
    string getRecipient()
    {
        return recipientContactNo;
    }
    string toString()
    {
        return "SMS to: " + recipientContactNo +
               "\nMessage: " + Message::toString();
    }
};
class Email : public Message{
private:
    string sender;
    string receiver;
    string subject;
public:
    void setSender(string s)
    {
        sender = s;
    }
    void setReceiver(string r)
    {
        receiver = r;
    }
    void setSubject(string s)
    {
        subject = s;
    }
    string getSender(){ return sender; }
    string getReceiver(){ return receiver; }
    string getSubject(){ return subject; }
    string toString()
    {
        return "Sender: " + sender +
               "\nReceiver: " + receiver +
               "\nSubject: " + subject +
               "\nMessage: " + Message::toString();
    }
};
bool ContainsKeyword(const Message& messageObject, const string& keyword)
{
    string text = messageObject.toString();

    if(text.find(keyword) != string::npos)
        return true;

    return false;
}
string EncodeMessage(string text)
{
    for(int i=0;i<text.length();i++)
    {
        if(text[i]=='Z')
            text[i]='A';
        else if(text[i]=='z')
            text[i]='a';
        else if(isalpha(text[i]))
            text[i]=text[i]+1;
    }
    return text;
}
int main()
{
    SMS sms1;
    sms1.setRecipient("03001234567");
    sms1.setText("Hello Vivek");
    cout<<sms1.toString()<<endl;
    Email email1;
    email1.setSender("vivek@gmail.com");
    email1.setReceiver("mahender@gmail.com");
    email1.setSubject("Leave");
    email1.setText("This is Java");
    cout<<"\n"<<email1.toString()<<endl;
    if(ContainsKeyword(email1,"Java"))
        cout<<"\nKeyword Found\n";
    else
        cout<<"\nKeyword Not Found\n";
    string encoded = EncodeMessage(email1.toString());
    cout<<"\nEncoded Message:\n"<<encoded;
}