#include<iostream>
#include<fstream>
using namespace std;
struct Employee {
    char name[50];
   int id;
   float salary;
};
void writeToFile(const Employee & employee){
ofstream outFile("employee.dat",ios:: binary);
if (!outFile){
cerr<<"Error:could not open the file for writing"<<endl;
return;
}
outFile.write(reinterpret_cast<const char*>(& employee),sizeof(employee));
outFile.close();
cout<<"Employee data written to binary file successfully!"<<endl;
}
void readFromFile(){
    Employee employee;
    ifstream infile("Employee.dat",ios:: binary);
    if(!infile){
        cerr<<"Error: could not open the file for reading!"<<endl;
        return;
    }
 infile.read(reinterpret_cast<char*>(& employee),sizeof(employee));
if(infile){
    cout<<"\nEmployee data read from binary file:"<<endl;
    cout<<"Name:"<<employee.name<<endl;
    cout<<"ID:"<<employee.id<<endl;
    cout<<"Salary:"<<employee.salary<<endl;
}else{
    cerr<<"Error: could not read data from the binary file!"<<endl;
}
infile.close();
}
int main(){
    Employee employee;
    cout<<"Enter employee details:\n";
    cout<<"Name:";
    cin.ignore();
    cin.getline(employee.name,50);
    cout<<"ID:";
    cin>>employee.id;
    cout<<"Salary:";
    cin>>employee.salary;
    writeToFile(employee);
    readFromFile();
    return 0;
    
}