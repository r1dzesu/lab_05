#include "simple.h"
#include "flag.h"

using std::pair;

void greetings() //func that just returns information about author and work
{
    cout << "\nKudriya Denis, K13, Lab05, var_44\n\n";
    cout << "Press Enter to Continue...";
    char temp1; while(temp1 != '\n') std::cin.get(temp1);

    cout << "\nWrite division of sequence in output.txt file with special subsequences(spiral, snake)\n\n";
    cout << "Press Enter to Continue...";
    char temp2; while(temp2 != '\n') std::cin.get(temp2);
}

void farewell()
{
  cout << "Program terminates, no problem found. Bye\n";
}

void test() // for fast check just change value N
{
  ofstream f("in.txt",  std::ofstream::out | std::ofstream::trunc);
  const int N = 12; // change to resize matrix in in.txt
  vector<vector<int>> check(N);
  int counter = 100;
  f << N << '\n';
  for(int i = 0; i < N; ++i)
  {
    for(int j = 0; j < N; ++j)
    {
      check[i].push_back(counter);
      ++counter;
    }
  }
  for(int i = 0; i < N; ++i)
  {
    for(int j = 0; j < N; ++j)
    {
      f << check[i][j] << " ";
    }
    f << '\n';
  }
}

int main(int argc, char* argv[]) // use this startup options: -i in.txt -o o
{
    //test(); //for fast check
    greetings(); // greeting message
    string IN, OUT;
    if(!get_args(argc, argv, IN, OUT)) //checking argc
    {
      help_flag(); // writing help message if something wrong with arguments 
      return 0;   
    }
    ifstream Input(IN); //opening in.txt
    ofstream Output(OUT, std::ofstream::out | std::ofstream::trunc); //opening out.txt
    try{
    Matrix input_maxtrix(Input); //constructing Matrix (see simple.cpp/simple.h) from given txt file

/*
    cout << input_maxtrix;
    for(auto & it: spiral(input_maxtrix))
    {
       cout << it << " ";
    }
    cout << '\n';
*/ // for fast check purpose

    pair<vector<int>, vector<int> > sequence{zmiyka(input_maxtrix),spiral(input_maxtrix)};
    Output << "First part: \n";
    for(auto&it: sequence.first)
    {
      Output << it << " ";
    }
    Output << "\nSecond part: \n";
     for(auto&it: sequence.second)
    {
      Output << it << " ";
    }
    Output << "\nResulting part: \n";
    for(int i = 0; i < sequence.first.size(); ++i)
    {
      Output << sequence.first[i] - sequence.second[i] << " ";
    }
    }
    catch(const std::invalid_argument& ia){
      Input.close();
      Output.close();
      std::cerr << "Invalid argument: " << ia.what() << '\n';
      return 0;
    }
    Input.close(); //closing txt
    Output.close(); // closing txt
    farewell(); // goodbye message
    
    return 1;
 }


