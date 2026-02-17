#include<iostream>
#include<ctime>
#include<iomanip>
#include<string>

using namespace std;

void randbingo(int *);
template<class T>
void show_table(T [][5]);
void showsetnum(int [],int);
void randnum(int [],int &);
void setscorefalse(bool *);
void check(int [][5],bool [][5],int [],int);
bool checkscore(bool *,int &);

int main(){
    int count = 0;
    int wincount = 0;
    int player_peper[5][5];
    int *dataP = player_peper[0];
    int setnum[100];
    bool score[5][5];
    bool *dataS = score[0];
    srand(time(0));
    setscorefalse(dataS);
    randbingo(dataP);
    show_table(player_peper);
    //ผู้เล่นเลือกกระดาษ
    string ans;
    do{
    cout << "do you want to pick another table?  [1]yes [2]no" << endl;
    cin >> ans;
    if(ans == "yes"){
        randbingo(dataP);
        show_table(player_peper);
    }else if(ans == "yes"){
        break;
    }else{
        do{
            cout << "please input 1/2 (yes/no)" << endl;
            cin >> ans;
        }while (ans != "yes" && ans != "no");
    }
    }while(ans != "no");
    //เริ่มเกมจนกว่าผู้เล่นจะปิงโกลได้แต้มอย่างน้อย 1
    do{
    randnum(setnum,count);
    check(player_peper,score,setnum,count);
    show_table(score);
    showsetnum(setnum,count);
    }while(!checkscore(dataS,wincount));
    cout << "score : " << wincount;
    return 0;
}

void randbingo(int *data){
    bool unique;
    for(int i=0;i<25;i++){
        do{
            *(data+i) = rand()%99+1;
            unique =true;
            for(int j=0;j<i;j++){
                if(*(data+i) == *(data+j)){
                    unique = false;
                }
            }
        }while(!unique);
    }
    *(data+12) = 0;
}

template<class T>
void show_table(T arr[][5]){
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            cout << setw(2) << arr[i][j] << " ";
        }
        cout << endl;
    }
    cout << "------------------------------------------------" << endl;
}

void showsetnum(int arr[],int N){
    for(int i=0;i<N;i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

void check(int inarr[][5],bool score[][5],int setnum[],int N){
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            if(inarr[i][j] == setnum[N-1]){
                score[i][j] = true;
            }
        }
    }
    score[2][2] = true;
}

void randnum(int arr[],int &count){
    bool unique;
    for(int i=0;i<count+1;i++){
        do{
            arr[count] = rand()%99+1;
            unique = true;
            for(int k=0;k<i;k++){
                if(arr[k] == arr[i]){
                    unique = false;
                }
            }
        }while(!unique);
    }
    count++;
}

void setscorefalse(bool *score){
    for(int i=0;i<25;i++){
        *(score+i) = false;
    }
}

bool checkscore(bool *data,int &wincount){
    bool win = false;
    if(*(data) && *(data+1) && *(data+2) && *(data+3) && *(data+4)){
        win = true;
        wincount++;
    }
    if(*(data+5) && *(data+6) && *(data+7) && *(data+8) && *(data+9)){
        win = true;
        wincount++;
    }
    if(*(data+10) && *(data+11) && *(data+12) && *(data+13) && *(data+14)){
        win = true;
        wincount++;
    }
    if(*(data+15) && *(data+16) && *(data+17) && *(data+18) && *(data+19)){
        win = true;
        wincount++;
    }
    if(*(data+20) && *(data+21) && *(data+22) && *(data+23) && *(data+24)){
        win = true;
        wincount++;
    }
    if(*(data) && *(data+6) && *(data+12) && *(data+18) && *(data+24)){
        win = true;
        wincount++;
    }
    if(*(data+4) && *(data+8) && *(data+12) && *(data+16) && *(data+20)){
        win = true;
        wincount++;
    }
    if(*(data) && *(data+5) && *(data+10) && *(data+15) && *(data+20)){
        win = true;
        wincount++;
    }
    if(*(data+1) && *(data+6) && *(data+11) && *(data+16) && *(data+21)){
        win = true;
        wincount++;
    }
    if(*(data+2) && *(data+7) && *(data+12) && *(data+17) && *(data+22)){
        win = true;
        wincount++;
    }
    if(*(data+3) && *(data+8) && *(data+13) && *(data+18) && *(data+23)){
        win = true;
        wincount++;
    }
    if(*(data+4) && *(data+9) && *(data+14) && *(data+19) && *(data+24)){
        win = true;
        wincount++;
    }
    return win;
}