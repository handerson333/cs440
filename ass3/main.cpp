#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>
#include <cstring>
#include <cstdio>
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <boost/tokenizer.hpp>

using namespace std;

void read_csv();

int main(){
  read_csv();

  //Read in department into Array1
  //Read in employee into Array2
  //Read 22 tubles of array 1
  //Sort array1 by 4th attribute

  //Save into run (Rn)

  //Loop until no more tuples



  //Read 22 tubles of array2
  //Sort array1 by 1st attribute

  //Save into run (Sn)

  //Loop until no more tuples



  //Read 4th attribute of 1st tuple in __ R runs

  //Read 1st attribute of 1st tuple in ___ S runs

  //Find smallest element

  //If same as another element, add R tuple to new array
  //else delete/advance pointer

  //move pointer of lowest into next tuple in the run

  //repeat untiol no more runs/tuples

  //create blank .csv

  //put merged array into .csv



/*
    FILE * pFile;
    char buffer [100];

    pFile = fopen ("department.csv" , "r");
    if (pFile == NULL) perror ("Error opening file");
    else
    {
        while ( ! feof (pFile) )
        {
            if ( fgets (buffer , 1000 , pFile) == NULL )
                break;
            fputs (buffer , stdout);
        }
        fclose (pFile);
    }

    std::ifstream myfile("employee.csv");

    if (myfile.is_open())
    {
        std::string line;
        while (std::getline(myfile, line))
        {
            typedef boost::escaped_list_separator<char> Separator;
            typedef boost::tokenizer<Separator> Tokenizer;

            std::vector<std::string> tokens;
            Tokenizer tokenizer(line);
            for (Tokenizer::iterator iter = tokenizer.begin(); iter != tokenizer.end(); ++iter)
            {
               tokens.push_back(*iter);
            }

            if (tokens.size() == 4)
            {
                std::cout << tokens[3] << "\n";
            }
            else
            {
                std::cerr << "\n";
            }
        }
    }
    */


/*
    int matrix[3][3] = {
        {7,8,9},
        {4,5,6},
        {1,2,3},
    };



    for(int i=0; i<3; i++){
        for (int j=0; j<3; j++){
            cout << matrix[i][j];
            if (j<2){
                cout << ",";
            }

        }
        cout << endl;
    }



    string hello;
    hello = "hello";
    cout << hello + "world!" << endl;
*/
    return 0;
};

void read_csv(){
  string line;
  ifstream myfile ("department.csv");
  int n  =0;
  while ( ! feof (myfile)){
    if (myfile.is_open())
    {
      while ( getline (myfile,line) )
      {
        cout << line << '\n';
        cout << n << endl;
        n++;
      }
      myfile.close();
    }
  }
/*

  FILE * pFile;
  char buffer [100];

  pFile = fopen ("department.csv" , "r");
  if (pFile == NULL) perror ("Error opening file");
  else
  {
      while ( ! feof (pFile) )
      {
          if ( fgets (buffer , 1000 , pFile) == NULL )
              break;
          fputs (buffer , stdout);
      }
      fclose (pFile);
  }
  */
}
