/*              Word Jumble!
* Lauren Vogel   COP3331    Summer 2020
*
*The program begins by opening a file "dictionary.txt"
*and reads all of the words in this file into a vector.
*Then it will wait for the user to type in a word and
*scan the vector of words to find any words that match.
*If it finds one or more words with the same letters
*given by the user, it should print all matching words,
*one per line. If there is no word in the dictionary
*with the same letters as the word the user typed in,
*the program should print the message "No matches" on
*a line. Either way, the program should continue to
*prompt the user for words and print all matches until
*the user types the word "quit". Matches for "quit"
*should not be printed before the program exits.
*
*Compile with g++
* * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#include <iostream>
#include <string>
#include <vector>
#include <cctype>
#include <fstream>
using namespace std;

const int ALPHABET_SIZE = 26;
const string DICTIONARY_FILE = "dictionary.txt";

//Counts how many times each letter appears in word
//Writes the 26 counts to int* count
void countLetters(string word, int* count)
{
        for(int i = 0; i < ALPHABET_SIZE; i++)
                count[i] = 0;

        for(int i = 0; i < word.size(); i++)
                ++count[ word[i] - 'a'];

        //we do not return from the void
}

//Returns whether or not word1 and word2 are permutations of each other
bool isJumble(string word1, string word2)
{
        int arr1[ALPHABET_SIZE], arr2[ALPHABET_SIZE];
        countLetters(word1, arr1);
        countLetters(word2, arr2);
        for(int i = 0; i < ALPHABET_SIZE; i++)
                if(arr1[i] != arr2[i])
                        return false;
        return true;
}

//Returns all of the strings in vec that are jumbles of word
vector<string> findMatches(string word, vector<string> vec)
{
        vector<string> matches;
        for(auto jumble : vec)
        {
                if(isJumble(jumble, word))
                        matches.push_back(jumble);
        }
        return matches;
}

int main()
{
  //Read in the dictionary from dictionary.txt
        string buffer;
        string jumble;
        ifstream word(DICTIONARY_FILE);
        vector<string> dictionary;
        while(word)
        {
                word >> buffer;
                dictionary.push_back(buffer);
        }

        cin >> jumble;
        while (jumble != "quit")
        {
                vector<string> matches;
                matches = findMatches(jumble, dictionary);
                if(matches.size() == 0)
                {  
                        cout << "No matches " << endl;
                        if(jumble == "scoobydoo")
                                cout << "Ruh Roh Raggy" << endl;
                }
                else
                        for(auto match : matches)//auto is a string so u could put string but we are here to have fUN
                                cout << match << endl;
                cin >> jumble;
        } 
        return 0;
}

