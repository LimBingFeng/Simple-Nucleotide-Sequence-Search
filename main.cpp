#include <iostream>
#include <string>
using namespace std;

// function prototype
void inputSequence(string& seq);
void searchSequence(string& searchSeq);
void calculation (string seq, string searchSeq);

int main()
{
    // declare variable sequence and search sequence,
    // choice and restart for sentinel control
    string seq, searchSeq;
    char choice;
    bool restart = true;

    // sentinel control
    while (restart)
    {
        cout << "******************************* Welcome ******************************" << endl;
        inputSequence(seq);
        searchSequence(searchSeq);
        calculation (seq,searchSeq);

        cout << "Do you want to restart the program?" << endl;
        cout << "Please enter 'Y' or 'y' to restart, others to quit" << endl;
        cin >> choice;
        if(choice == 'Y' || choice == 'y')
        {
            system("cls");
        }
        else
        {
            restart = false;
            cout << "Thank you!" << endl;
        }
    }
}

// user input gene sequence
void inputSequence(string& seq)
{
    cout << "Please enter a nucleotide sequence containing only 'G', 'A', 'C', 'T'" << endl;
    cin >> seq;

   // check every character
    for (int i = 0; i < seq.length(); i++)
    {
        if (seq[i] == 'A' || seq[i] == 'C' || seq[i] == 'G' || seq[i] == 'T')
            continue;
        else
        {
            cout << "Invalid input! Please try again!" << endl;
            inputSequence(seq);
        }
    }
}

// user input string that they want to search
void searchSequence(string& searchSeq)
{
    cout << "Please enter the search sequence containing only 'G', 'A', 'C', 'T'" << endl;
    cin >> searchSeq;

    // check every character
     for (int i = 0; i < searchSeq.length(); i++)
    {
        if (searchSeq[i] == 'A' || searchSeq[i] == 'C' || searchSeq[i] == 'G' || searchSeq[i] == 'T')
            continue;
        else
        {
            cout << "Invalid input! Please try again!" << endl;
            searchSequence(searchSeq);
        }
    }
}

// search for certain string in sequence,
// count the occurrence of each character
// printing result
void calculation (string seq, string searchSeq)
{
    // declaring a,c,g,t for the occurences
    int a = 0, c = 0, g = 0, t = 0;

    cout << "\n\nResults:\n" << endl;
    // search for certain string in sequence,
    size_t index = seq.find(searchSeq);
    if (index != string::npos)
    {
      cout << "The search sequence is found at index " << index << endl;
    }
    else
    {
        cout << "No similar sequence found!" << endl;
    }

// count the occurrence of each character
    for (int i = 0 ; i < seq.length() ; i++)
    {
        if (seq[i] == 'A')
        {
            a+=1;
        }
        else if (seq[i] == 'C')
        {
            c+=1;
        }
        else if (seq[i] == 'G')
        {
            g+=1;
        }
        else
        {
            t+=1;
        }
    }

    // printing result
    cout << "Occurrences of each nucleotide" << endl;
    cout << "A: " << a << " times" << endl;
    cout << "C: " << c << " times" << endl;
    cout << "G: " << g << " times" << endl;
    cout << "T: " << t << " times" << endl;
    cout << endl;
}
