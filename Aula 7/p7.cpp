#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <iomanip>
#include <vector>
#include <algorithm>

using namespace std;

//exercicio 1
int count(const string& fname, const string& word){
    ifstream f(fname);
    string aux;
    int count = 0;

    string w = word;

    for (char &c: w) c = toupper(c);

    while(f>>aux){
        for(char &c: aux) c=toupper(c);

        if(aux==w) count++;
    }

    return count;
}

//exercicio 2

struct wcresult {
  unsigned int lines;
  unsigned int words;
  unsigned int bytes;
};

wcresult wc(const string& filename){
    ifstream f(filename);
    wcresult ret {0, 0, 0};
    string line, aux;

    while(getline(f, line)){
        ret.lines++;
        ret.bytes++;

        for(char c: line){
            c=c; 
            ret.bytes++;
        }

        istringstream iss (line);

        while(iss >> aux) ret.words++;
    }

    return ret;
}

//exercicio 3

//! Show file contents with line number information and 
//! the '|' character indicating the begining and end of lines.
void print(const std::string& file) {
  ifstream in(file);
  size_t line_nr = 1;
  for (string line; getline(in, line);) {
     cout << line_nr << "|" << line << "|\n";
     line_nr++;
  }
}

void normalise(const string& input_fname, const string& output_fname){
    ifstream f(input_fname);
    ofstream of(output_fname);
    string line;

    while(getline(f, line)){
        for(char &c : line) c = toupper(c);

        line.erase(0, line.find_first_not_of(" ",0));
        line.erase(line.find_last_not_of(" ", line.length())+1, SIZE_MAX);

        if(line!=""){
            of << line << "\n";
        }
    }
}


//exercicio 4
double average(const string& fname) {
    double counter = 0;
    double sadd = 0;
    double num = 0;

    ifstream in(fname);

    while(!in.eof()) {
        if (in >> num) {
            sadd += num;
            counter++;
        }
        else {
            in.clear();
            in.ignore(1);
        }
    }

    return sadd/counter;
}

//exercicio 5
//! Show file name and the contents.
void show_file(const string& file) {
  ifstream in(file);
  cout << "==> " << file << " <==\n";
  for (string line; getline(in, line); ) cout << line << '\n';
}

void calc_medians(const string& input_fname, const string& output_fname)
{
    ifstream in(input_fname);
    ofstream out(output_fname);
    string line;
    string x;
    double z;
    vector<double> v;
    while(getline(in,line))
    {
        stringstream iss(line);
        iss >> x;
        if(x[0] == '#') continue;
        while(iss >> z) v.push_back(z);
        sort(v.begin(), v.end());
        if(v.size()%2!=0) out << fixed << setprecision(1) << x << ' ' << v[v.size()/2] << "\n";
        else out << fixed << setprecision(1) << x << ' ' << 0.5*(v[v.size()/2-1]+v[v.size()/2]) << "\n";
        v.clear();
    }
}

int main(){
    
    /* TESTES PRIVADOS EXERCICIO 1
    cout << count("p1_test_a.txt", "exerCISE") << '\n';  // -> 1
    cout << count("p1_test_b.txt", "feeling") << '\n';   // -> 0
    cout << count("p1_test_b.txt", "feelings") << '\n';  // -> 1
    cout << count("p1_test_b.txt", "i") << '\n';         // -> 5
    cout << count("p1_test_b.txt", "lOvE") << '\n';      // -> 4
    */

    /* TESTES PRIVADOS EXERCICIO 2
    {
    wcresult r = wc("p2_test6.txt"); 
    cout << r.lines << ' ' << r.words << ' ' << r.bytes << '\n';
    } // -> 1 14 94
    {
        wcresult r = wc("p2_test7.txt"); 
        cout << r.lines << ' ' << r.words << ' ' << r.bytes << '\n';
    } // -> 14 74 419
    {
        wcresult r = wc("p2_test8.txt"); 
        cout << r.lines << ' ' << r.words << ' ' << r.bytes << '\n';
    } // -> 9 125 830
    {
        wcresult r = wc("p2_test9.txt"); 
        cout << r.lines << ' ' << r.words << ' ' << r.bytes << '\n';
    } // -> 3335 26443 144390
    {
        wcresult r = wc("p2_test10.txt"); 
        cout << r.lines << ' ' << r.words << ' ' << r.bytes << '\n';
    } // -> 34 223 1106
    */

    /* TESTES PRIVADOS EXERCICIO 3
    {
    normalise("p3_test6.txt", "p3_test6_out.txt"); 
    print("p3_test6_out.txt");
    printf("\n");
    }  ->
    1|TO TEST YOUR CODE DOWNLOAD THE EX3.ZIP|
    2|ARCHIVE CONTAINING THE TEXT FILES USED IN|
    3|PUBLIC TESTS (P3_TEST[1-5].TXT).|
    

    
    {
        normalise("p3_test7.txt", "p3_test7_out.txt"); 
        print("p3_test7_out.txt");
        printf("\n");
    } // ->
    
    1|YOU MAY ASSUME THAT THE ONLY BLANK CHARACTERS CONTAINED IN|
    2|FILES ARE THE SPACE AND NEWLINE CHARACTER.|
    
    
    {
        normalise("p3_test8.txt", "p3_test8_out.txt"); 
        print("p3_test8_out.txt");
        printf("\n");
    } // ->
    
    1|HINTS: YOU SHOULD USE AN  OFSTREAM  OBJECT TO WRITE|
    2|THE OUTPUT FILE.|
    3|YOU MAY USE TOUPPER TO CONVERT CHARACTERS TO UPPERCASE.|
    
    
    {
        normalise("p3_test9.txt", "p3_test9_out.txt"); 
        print("p3_test9_out.txt");
        printf("\n");
    } // ->
    
    1|{|
    2|WCRESULT R = WC("P2_TEST6.TXT");|
    3|COUT << R.LINES << ' ' << R.WORDS << ' ' << R.BYTES << '\N';|
    4|} // -> 1 14 94 // -> 14 74 419|
    
    
    {
        normalise("p3_test10.txt", "p3_test10_out.txt"); 
        print("p3_test10_out.txt");
        printf("\n");
    } // ->
    
    1|WCRESULT R { 0, 0, 0 };|
    2|FOR (STRING LINE; GETLINE(IN, LINE);) {|
    3|R.LINES++;|
    4|R.BYTES += LINE.LENGTH() + 1;|
    
    */
}