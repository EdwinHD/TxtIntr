#include <iostream>
#include <getopt.h>

using namespace std;

int main(int argc, char *argv[]){
    string s1 = "Запустите через командную строку makefile и Введите один из параметров:\n -h — вывод справки\n -a — cложение всех введенных значений\n -s — вычетание первого значения из всех последующий введенных значений\n -m — умножние первого значения на все последующие введенные значения\n -d — ЦЕЛОЧИСЛЕННОЕ деление введенных значений относительно первого\n Программа производит действия первого числа над вторым и тд. (первое - второе)\n";
    if (argc==1){
        cout<< s1 << endl;
    }        
    int opt, i, res = 0, x, b, a, t = 1;
    while ((opt = getopt (argc, argv, "a:s:m:d:h")) != -1){
        switch (opt){
            case 'h':
                cout<< s1;
            break;
            case 'a':
                for(i = 0; i<argc; i++){
                    cout<< i << ": "<< argv[i] << endl;
                }			
                for(i=2; i<argc; i++){
                    x = strtol(argv[i], NULL, 10);
                    res=res + x;
                }
                cout<< "Результат: "<< res<<endl;
                break;
            
            case 's':
                for(i = 0; i<argc; i++){
                    cout<< i << ": "<< argv[i] << endl;
                }	
                b = 0;
                for(i=2; i<argc; i++){
                    int bruh;
                    bruh = strtol(argv[i], NULL, 10);
                    b = b-bruh;
                    //cout<<"bruh RAVNO"<< bruh << endl;
                    //cout<< "b RAVNO"<<b << endl;
                }
                a = strtol(argv[2], NULL, 10);
                cout<< "Результат: "<< a*2 + b <<endl;
                break;
                
            case 'm':
                for(i = 0; i<argc; i++){
                    cout<< i << ": "<< argv[i] << endl;
                }			
                for(i=2; i<argc; i++){
                    x = strtol(argv[i], NULL, 10);
                    t=t*x;
                }
                cout<< "Результат: "<< t<<endl;
                break;
            
            case 'd':
                for(i = 0; i<argc; i++){
                    cout<< i << ": "<< argv[i] << endl;
                }	
                b = strtol(argv[2], NULL, 10);
                for(i=3; i<argc; i++){
                    int bruh;
                    bruh = strtol(argv[i], NULL, 10);
                    b = b/bruh;
                    //cout<<"bruh RAVNO"<< bruh << endl;
                    //cout<< "b RAVNO"<<b << endl;
                }
                a = strtol(argv[2], NULL, 10);
                cout<< "Результат: "<< b <<endl;
                break;
        }
    }
}
