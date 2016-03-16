// By KRT girl xiplus
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
void SHOW(){
	cout<<"-------------------------------------"<<endl;
	cout<<"1. Start    2. Stop  3. Set SSID"<<endl;
	cout<<"4. Set key  5. Show  6. Show security"<<endl;
	cout<<"command >";
}
int main(){
	system("title Wi-Fi AP Configurator");
	string s;
	stringstream cmd;
	int n;
	char c;
	system("netsh wlan set hostednetwork mode=allow");
	SHOW();
	while(cin>>n){
		switch(n){
			case 1:
				system("netsh wlan start hostednetwork");
			break;
			case 2:
				system("netsh wlan stop hostednetwork");
			break;
			case 3:
				cin.ignore();
				while(true){
					cout<<"New SSID >";
					getline(cin,s);
					if(s.size()<=32)break;
					else cout<<"Fail! Should between 1 and 32 characters."<<endl;
				}
				if(s.size()>0){
					cmd<<"netsh wlan set hostednetwork ssid=\""<<s<<"\"";
					system(cmd.str().c_str());
					cmd.str("");
				}else {
					cout<<"No changes."<<endl;
				}
			break;
			case 4:
				cin.ignore();
				while(true){
					cout<<"New key >";
					getline(cin,s);
					bool x=0;
					for(int q=0;q<s.size();q++)if(!((s[q]<='9'&&s[q]>='0')||(s[q]<='Z'&&s[q]>='A')||(s[q]<='z'&&s[q]>='a')))x=1;
					if((s.size()>=8&&s.size()<=63&&x==0)||s.size()==0)break;
					else if(!(s.size()>=8&&s.size()<=63))cout<<"Fail! Should between 8 and 63 characters."<<endl;
					else cout<<"Fail! Only allow A-Za-z0-9."<<endl;
				}
				if(s.size()>0){
					cmd<<"netsh wlan set hostednetwork key="<<s;
					system(cmd.str().c_str());
					cmd.str("");
					system("netsh wlan refresh hostednetwork key");
				}else {
					cout<<"No changes."<<endl;
				}
			break;
			case 5:
				system("netsh wlan show hostednetwork");
			break;
			case 6:
				system("netsh wlan show hostednetwork setting=security");
			break;
		}
		SHOW();
	}
}
