#include<cstdio>
#include<map>
#include<string>
#include<iostream>
#include<cstring>
#include<string>

using namespace std;

int main(){
	int n;
	while(scanf("%d\n",&n)!=EOF){

		map<string,int> m;
		map<string,int>::iterator it;
		
		string str;	
		for(int i = 0;i<n;++i){
			/* cut the string to nation */
			getline(cin,str);
			char *temp = new char [str.length()+1];			
			strcpy(temp,str.c_str());
			char *nat = strtok(temp," ");
			string data(nat);
			/* insert to the map,and update the value */
			pair<map<string,int>::iterator,bool>insert_pair;
			insert_pair = m.insert(pair<string,int>(data,1));
			if(insert_pair.second == false){
				it = m.find(data);
				(*it).second++;
			}
		}
		/* print the map */
		for(it = m.begin();it != m.end();++it){
			cout << it->first << " " << it->second << endl;
		}

	}
	return 0;
}
