#include "Country.h"

int split(string s, char sep, string words[], int max_words);

        Country::Country(){
            for(int i=0;i<50;i++){
                countries[i]="";
                capitals[i]="";
            }
        }
        int Country::LoadCountry(string filename){
            ifstream in;
            string arr[50];
            in.open(filename);
            int linenum=0;
            string line;
            int max_words;
            if(in.fail()){
                return -1;
            }else{
                while(getline(in,line)){
                    int index=0;
                    index=split(line,',', arr, max_words);
                    for(int i=0; i<50; i++){
                        countries[i]=arr[index];
                        capitals[i]=arr[i];
                    }
                }

            }
        }
        int Country::SearchForCountry(string country){
            //string fileName="country3.txt";
            //LoadCountry(fileName);
            int index=0;
            for(int i=0; i<50; i++){
                if(country==countries[i]){
                    index=i;
                    return i;
                }
            }
            if(index==0){
                return 0;
            }
        }
        string Country::GetCapital(string country){
            //string fileName="country3.txt";
            //LoadCountry(fileName);
            int index=0;
            for(int i=0; i<50; i++){
                if(country==countries[i]){
                    index=i;
                    return capitals[i];
                }
            }
            if(index==0){
                return "";
            }
        }