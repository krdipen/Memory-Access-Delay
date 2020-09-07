#include<iostream>
#include<fstream>
#include<sstream>
#include<string>
#include<vector>
#include<math.h>

using namespace std;

int main(int argc,char *argv[]){
    int i,num;
    string str;
    ifstream infile;
    ofstream outfile1;
    ofstream outfile2;
    //parameters
    cout<<endl;
    srand(time(0));
    double x;
    cout<<"please enter HIT rate (X): ";
    cin>>x;
    int N;
    cout<<"please enter MISS penalty (N): ";
    cin>>N;
    //register file
    vector<int> reg(32,0);
    reg[29]=4096;
    //text memory
    vector<string> text;
    infile.open(argv[1]);
    while(getline(infile,str)){
        if(str!=""){
            text.push_back(str);
        }
    }
    infile.close();
    //data memory
    vector<int> data(4096,0);
    infile.open(argv[2]);
    i=0;
    while(infile>>num){
        data[i]=num;
        i++;
    }
    infile.close();
    //pipelined registers
    int pc=0;
    istringstream inst;
    inst.str("clear");
    string cmd="clear";
    string cmd2="clear";
    string cmd3="clear";
    int ra,ra1,ra2,ra3,ra4;
    int wb,wb2;
    int value,value2;
    int num1,num2,num3;
    int reg1,reg2,reg3;
    int result;
    bool branch=false;
    bool forward=false;
    bool forward2=false;
    bool stall=false;
    int result_h,wb_h;
    int value2_h,wb2_h;
    int num1_h;
    int cycle=0;
    int instruct=0;
    int index1=0;
    int index2=text.size();
    int index3=text.size();
    int index4=text.size();
    int index5=text.size();
    text.push_back("nop");
    //processor
    outfile1.open("register.txt");
    outfile2.open("memory.txt");
    for(int j=0;j<reg.size();j++){
        outfile1<<reg[j]<<" ";
    }
    for(int j=0;j<data.size();j++){
        outfile2<<data[j]<<" ";
    }
    label1:
    while(true){
        cout<<endl;
        cout<<"cycle: "<<cycle+1<<endl;
        cout<<"stage5 (WB): "<<text[index5]<<endl;
        cout<<"stage4 (MEM): "<<text[index4]<<endl;
        cout<<"stage3 (EX): "<<text[index3]<<endl;
        cout<<"stage2 (ID): "<<text[index2]<<endl;
        cout<<"stage1 (IF): "<<text[index1]<<endl;
        //stage:5(WB)
        if(cmd3=="add"){
            reg[wb2]=value2;
            forward2=true;
            value2_h=value2;
            wb2_h=wb2;
            instruct++;
        }
        else if(cmd3=="sub"){
            reg[wb2]=value2;
            forward2=true;
            value2_h=value2;
            wb2_h=wb2;
            instruct++;
        }
        else if(cmd3=="sll"){
            reg[wb2]=value2;
            forward2=true;
            value2_h=value2;
            wb2_h=wb2;
            instruct++;
        }
        else if(cmd3=="srl"){
            reg[wb2]=value2;
            forward2=true;
            value2_h=value2;
            wb2_h=wb2;
            instruct++;
        }
        else if(cmd3=="lw"){
            reg[wb2]=value2;
            forward2=true;
            value2_h=value2;
            wb2_h=wb2;
            instruct++;
        }
        else if(cmd3=="jal"){
            reg[31]=ra3;
            instruct++;
        }
        else if(cmd3=="clear"){

        }
        //stage:4(MEM)
        if(cmd2=="add"){
            index5=index4;
            wb2=wb;
            value2=result;
            cmd3=cmd2;
            forward=true;
            result_h=result;
            wb_h=wb;
        }
        else if(cmd2=="sub"){
            index5=index4;
            wb2=wb;
            value2=result;
            cmd3=cmd2;
            forward=true;
            result_h=result;
            wb_h=wb;
        }
        else if(cmd2=="sll"){
            index5=index4;
            wb2=wb;
            value2=result;
            cmd3=cmd2;
            forward=true;
            result_h=result;
            wb_h=wb;
        }
        else if(cmd2=="srl"){
            index5=index4;
            wb2=wb;
            value2=result;
            cmd3=cmd2;
            forward=true;
            result_h=result;
            wb_h=wb;
        }
        else if(cmd2=="lw"){
            if((rand()>RAND_MAX*x)||(x==0)){
                for(int j=0;j<N-1;j++){
                    cout<<endl;
                    cycle++;
                    cout<<"cycle: "<<cycle+1<<endl;
                    cout<<"stage5 (WB): "<<text[text.size()-1]<<endl;
                    cout<<"stage4 (MEM): "<<text[index4]<<endl;
                    cout<<"stage3 (EX): "<<text[index3]<<endl;
                    cout<<"stage2 (ID): "<<text[index2]<<endl;
                    cout<<"stage1 (IF): "<<text[index1]<<endl;
                    outfile1<<endl<<endl;
                    for(int j=0;j<reg.size();j++){
                        outfile1<<reg[j]<<" ";
                    }
                    outfile2<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
                    for(int j=0;j<data.size();j++){
                        outfile2<<data[j]<<" ";
                    }
                }
            }
            index5=index4;
            wb2=wb;
            value2=data[result];
            cmd3=cmd2;
        }
        else if(cmd2=="sw"){
            if((rand()>RAND_MAX*x)||(x==0)){
                for(int j=0;j<N-1;j++){
                    cout<<endl;
                    cycle++;
                    cout<<"cycle: "<<cycle+1<<endl;
                    cout<<"stage5 (WB): "<<text[text.size()-1]<<endl;
                    cout<<"stage4 (MEM): "<<text[index4]<<endl;
                    cout<<"stage3 (EX): "<<text[index3]<<endl;
                    cout<<"stage2 (ID): "<<text[index2]<<endl;
                    cout<<"stage1 (IF): "<<text[index1]<<endl;
                    outfile1<<endl<<endl;
                    for(int j=0;j<reg.size();j++){
                        outfile1<<reg[j]<<" ";
                    }
                    outfile2<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
                    for(int j=0;j<data.size();j++){
                        outfile2<<data[j]<<" ";
                    }
                }
            }
            index5=index4;
            data[result]=value;
            cmd3="clear";
            instruct++;
        }
        else if(cmd2=="jal"){
            index5=index4;
            ra3=ra2;
            cmd3=cmd2;
        }
        else if(cmd2=="stop"){
            cycle++;
            outfile1<<endl<<endl;
            for(int j=0;j<reg.size();j++){
                outfile1<<reg[j]<<" ";
            }
            outfile2<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
            for(int j=0;j<data.size();j++){
                outfile2<<data[j]<<" ";
            }
            break;
        }
        else if(cmd2=="clear"){
            index5=index4;
            cmd3=cmd2;
        }
        //stage:3(EX)
        if(cmd=="add"){
            index4=index3;
            if((num2==wb_h)&&(forward)){
                reg2=result_h;
            }
            else if((num2==wb2_h)&&(forward2)){
                reg2=value2_h;
            }
            if((num3==wb_h)&&(forward)){
                reg3=result_h;
            }
            else if((num3==wb2_h)&&(forward2)){
                reg3=value2_h;
            }
            result=reg2+reg3;
            cmd2=cmd;
            wb=num1;
        }
        else if(cmd=="sub"){
            index4=index3;
            if((num2==wb_h)&&(forward)){
                reg2=result_h;
            }
            else if((num2==wb2_h)&&(forward2)){
                reg2=value2_h;
            }
            if((num3==wb_h)&&(forward)){
                reg3=result_h;
            }
            else if((num3==wb2_h)&&(forward2)){
                reg3=value2_h;
            }
            result=reg2-reg3;
            cmd2=cmd;
            wb=num1;
        }
        else if(cmd=="sll"){
            index4=index3;
            if((num2==wb_h)&&(forward)){
                reg2=result_h;
            }
            else if((num2==wb2_h)&&(forward2)){
                reg2=value2_h;
            }
            result=reg2*pow(2,num3);
            cmd2=cmd;
            wb=num1;
        }
        else if(cmd=="srl"){
            index4=index3;
            if((num2==wb_h)&&(forward)){
                reg2=result_h;
            }
            else if((num2==wb2_h)&&(forward2)){
                reg2=value2_h;
            }
            result=reg2/pow(2,num3);
            cmd2=cmd;
            wb=num1;
        }
        else if(cmd=="lw"){
            index4=index3;
            if((num2==wb_h)&&(forward)){
                reg2=result_h;
            }
            else if((num2==wb2_h)&&(forward2)){
                reg2=value2_h;
            }
            result=reg2+num3;
            cmd2=cmd;
            wb=num1;
            num1_h=num1;
            stall=true;
        }
        else if(cmd=="sw"){
            index4=index3;
            if((num1==wb_h)&&(forward)){
                reg1=result_h;
            }
            else if((num1==wb2_h)&&(forward2)){
                reg1=value2_h;
            }
            if((num2==wb_h)&&(forward)){
                reg2=result_h;
            }
            else if((num2==wb2_h)&&(forward2)){
                reg2=value2_h;
            }
            result=reg2+num3;
            cmd2=cmd;
            value=reg1;
        }
        else if(cmd=="jr"){
            index4=index3;
            cmd="clear";
            index3=text.size()-1;
            inst.clear();
            inst.str("clear");
            index2=text.size()-1;
            if((num1==wb_h)&&(forward)){
                reg1=result_h;
            }
            else if((num1==wb2_h)&&(forward2)){
                reg1=value2_h;
            }
            pc=reg1;
            if(text[pc]=="stop"){
                index1=text.size()-1;
            }
            else{
                index1=pc;
            }
            branch=true;
            cmd2="clear";
            instruct++;
            break;
        }
        else if(cmd=="j"){
            index4=index3;
            cmd="clear";
            index3=text.size()-1;
            inst.clear();
            inst.str("clear");
            index2=text.size()-1;
            pc=num1;
            if(text[pc]=="stop"){
                index1=text.size()-1;
            }
            else{
                index1=pc;
            }
            branch=true;
            cmd2="clear";
            instruct++;
            break;
        }
        else if(cmd=="jal"){
            index4=index3;
            cmd="clear";
            index3=text.size()-1;
            inst.clear();
            inst.str("clear");
            index2=text.size()-1;
            pc=num1;
            if(text[pc]=="stop"){
                index1=text.size()-1;
            }
            else{
                index1=pc;
            }
            branch=true;
            cmd2="jal";
            ra2=ra1;
            break;
        }
        else if(cmd=="beq"){
            index4=index3;
            if((num1==wb_h)&&(forward)){
                reg1=result_h;
            }
            else if((num1==wb2_h)&&(forward2)){
                reg1=value2_h;
            }
            if((num2==wb_h)&&(forward)){
                reg2=result_h;
            }
            else if((num2==wb2_h)&&(forward2)){
                reg2=value2_h;
            }
            if(reg1==reg2){
                cmd="clear";
                index3=text.size()-1;
                inst.clear();
                inst.str("clear");
                index2=text.size()-1;
                pc=pc-1+num3;
                if(text[pc]=="stop"){
                    index1=text.size()-1;
                }
                else{
                    index1=pc;
                }
                branch=true;
                cmd2="clear";
                break;
            }
            cmd2="clear";
            instruct++;
        }
        else if(cmd=="bne"){
            index4=index3;
            if((num1==wb_h)&&(forward)){
                reg1=result_h;
            }
            else if((num1==wb2_h)&&(forward2)){
                reg1=value2_h;
            }
            if((num2==wb_h)&&(forward)){
                reg2=result_h;
            }
            else if((num2==wb2_h)&&(forward2)){
                reg2=value2_h;
            }
            if(reg1!=reg2){
                cmd="clear";
                index3=text.size()-1;
                inst.clear();
                inst.str("clear");
                index2=text.size()-1;
                pc=pc-1+num3;
                if(text[pc]=="stop"){
                    index1=text.size()-1;
                }
                else{
                    index1=pc;
                }
                branch=true;
                cmd2="clear";
                break;
            }
            cmd2="clear";
            instruct++;
        }
        else if(cmd=="blez"){
            index4=index3;
            if((num1==wb_h)&&(forward)){
                reg1=result_h;
            }
            else if((num1==wb2_h)&&(forward2)){
                reg1=value2_h;
            }
            if(reg1<=0){
                cmd="clear";
                index3=text.size()-1;
                inst.clear();
                inst.str("clear");
                index2=text.size()-1;
                pc=pc-1+num2;
                if(text[pc]=="stop"){
                    index1=text.size()-1;
                }
                else{
                    index1=pc;
                }
                branch=true;
                cmd2="clear";
                break;
            }
            cmd2="clear";
            instruct++;
        }
        else if(cmd=="bgtz"){
            index4=index3;
            if((num1==wb_h)&&(forward)){
                reg1=result_h;
            }
            else if((num1==wb2_h)&&(forward2)){
                reg1=value2_h;
            }
            if(reg1>0){
                cmd="clear";
                index3=text.size()-1;
                inst.clear();
                inst.str("clear");
                index2=text.size()-1;
                pc=pc-1+num2;
                if(text[pc]=="stop"){
                    index1=text.size()-1;
                }
                else{
                    index1=pc;
                }
                branch=true;
                cmd2="clear";
                break;
            }
            cmd2="clear";
            instruct++;
        }
        else if(cmd=="stop"){
            index4=index3;
            cmd2=cmd;
            branch=true;
            break;
        }
        else if(cmd=="clear"){
            index4=index3;
            cmd2=cmd;
        }
        forward=false;
        forward2=false;
        //stage:2(ID)
        inst>>cmd;
        if(cmd=="add"){
            index3=index2;
            inst>>num1>>num2>>num3;
            reg2=reg[num2];
            reg3=reg[num3];
            if(stall){
                if((num1_h==num2)||(num1_h==num3)){
                    cmd="clear";
                    index3=text.size()-1;
                }
                else{
                    stall=false;
                }
            }
        }
        else if(cmd=="sub"){
            index3=index2;
            inst>>num1>>num2>>num3;
            reg2=reg[num2];
            reg3=reg[num3];
            if(stall){
                if((num1_h==num2)||(num1_h==num3)){
                    cmd="clear";
                    index3=text.size()-1;
                }
                else{
                    stall=false;
                }
            }
        }
        else if(cmd=="sll"){
            index3=index2;
            inst>>num1>>num2>>num3;
            reg2=reg[num2];
            if(stall){
                if(num1_h==num2){
                    cmd="clear";
                    index3=text.size()-1;
                }
                else{
                    stall=false;
                }
            }
        }
        else if(cmd=="srl"){
            index3=index2;
            inst>>num1>>num2>>num3;
            reg2=reg[num2];
            if(stall){
                if(num1_h==num2){
                    cmd="clear";
                    index3=text.size()-1;
                }
                else{
                    stall=false;
                }
            }
        }
        else if(cmd=="lw"){
            index3=index2;
            inst>>num1>>num2>>num3;
            reg2=reg[num2];
            if(stall){
                if(num1_h==num2){
                    cmd="clear";
                    index3=text.size()-1;
                }
                else{
                    stall=false;
                }
            }
        }
        else if(cmd=="sw"){
            index3=index2;
            inst>>num1>>num2>>num3;
            reg1=reg[num1];
            reg2=reg[num2];
            if(stall){
                if((num1_h==num1)||(num1_h==num2)){
                    cmd="clear";
                    index3=text.size()-1;
                }
                else{
                    stall=false;
                }
            }
        }
        else if(cmd=="jr"){
            index3=index2;
            inst>>num1;
            reg1=reg[num1];
            if(stall){
                if(num1_h==num1){
                    cmd="clear";
                    index3=text.size()-1;
                }
                else{
                    stall=false;
                }
            }
        }
        else if(cmd=="j"){
            index3=index2;
            inst>>num1;
            if(stall){
                stall=false;
            }
        }
        else if(cmd=="jal"){
            index3=index2;
            inst>>num1;
            ra1=ra;
            if(stall){
                stall=false;
            }
        }
        else if(cmd=="beq"){
            index3=index2;
            inst>>num1>>num2>>num3;
            reg1=reg[num1];
            reg2=reg[num2];
            if(stall){
                if((num1_h==num1)||(num1_h==num2)){
                    cmd="clear";
                    index3=text.size()-1;
                }
                else{
                    stall=false;
                }
            }
        }
        else if(cmd=="bne"){
            index3=index2;
            inst>>num1>>num2>>num3;
            reg1=reg[num1];
            reg2=reg[num2];
            if(stall){
                if((num1_h==num1)||(num1_h==num2)){
                    cmd="clear";
                    index3=text.size()-1;
                }
                else{
                    stall=false;
                }
            }
        }
        else if(cmd=="blez"){
            index3=index2;
            inst>>num1>>num2;
            reg1=reg[num1];
            if(stall){
                if(num1_h==num1){
                    cmd="clear";
                    index3=text.size()-1;
                }
                else{
                    stall=false;
                }
            }
        }
        else if(cmd=="bgtz"){
            index3=index2;
            inst>>num1>>num2;
            reg1=reg[num1];
            if(stall){
                if(num1_h==num1){
                    cmd="clear";
                    index3=text.size()-1;
                }
                else{
                    stall=false;
                }
            }
        }
        else if(cmd=="stop"){
            index3=index2;
            index1=text.size()-1;
            if(stall){
                stall=false;
            }
            if((cmd2!="clear")||(cmd3!="clear")){
                branch=true;
            }
            break;
        }
        else if(cmd=="clear"){
            index3=index2;
            if(stall){
                stall=false;
            }
        }
        //stage:1(IF)
        inst.clear();
        if(stall){
            pc--;
            index1--;
            stall=false;
        }
        inst.str(text[pc]);
        ra=pc+1;
        index2=index1;
        //stage:0(PC)
        pc++;
        if(text[pc]=="stop"){
            index1=text.size()-1;
        }
        else{
            if((index2==text.size()-1)&&(index3==index2)&&(index4==index2)){
                index1=text.size()-1;
            }
            else{
                index1=pc;
            }
        }
        cycle++;
        outfile1<<endl<<endl;
        for(int j=0;j<reg.size();j++){
            outfile1<<reg[j]<<" ";
        }
        outfile2<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
        for(int j=0;j<data.size();j++){
            outfile2<<data[j]<<" ";
        }
    }
    if(branch){
        branch=false;
        cycle++;
        outfile1<<endl<<endl;
        for(int j=0;j<reg.size();j++){
            outfile1<<reg[j]<<" ";
        }
        outfile2<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
        for(int j=0;j<data.size();j++){
            outfile2<<data[j]<<" ";
        }
        goto label1;
    }
    cout<<endl;
    cout<<"instruction counts: "<<instruct<<endl;
    cout<<"clock cycle counts: "<<cycle<<endl;
    cout<<"instructions per cycle (IPC): "<<instruct*1.0/cycle<<endl;
    cout<<endl;
    return 0;
}
