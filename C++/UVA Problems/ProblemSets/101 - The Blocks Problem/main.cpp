/**<  The Input
The input begins with an integer n on a line by itself representing the number of blocks in the block world. You may assume that 0 < n < 25.

The number of blocks is followed by a sequence of block commands, one command per line.
Your program should process all commands until the quit command is encountered.

You may assume that all commands will be of the form specified above.
There will be no syntactically incorrect commands.  */

/**<  The Output

The output should consist of the final state of the blocks world.
Each original block position numbered i ( 0 <= i < n where n is the number of blocks)
should appear followed immediately by a colon. If there is at least a block on it,
the colon must be followed by one space,
followed by a list of blocks that appear stacked in that position
with each block number separated from other block numbers by a space.
Don't put any trailing spaces on a line.  */
#include <iostream>
#include <list>
#include <string>
#include <iterator>
#include <algorithm>
#include <sstream>
#include <cstdlib>
typedef std::list<int> stacky;
typedef std::list<stacky> piles;

typedef stacky::iterator stIT;
typedef piles::iterator pIT;
typedef std::string::const_iterator cchIT;
/** \brief
 * struct class to work with the problem set 101 from
 * http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=3&page=show_problem&problem=37
 */
struct pilestruct
{
 public:
 pilestruct(unsigned int max_piles);
  /**< Will print the current pile compositions */
 void PrintStats();
 /**<
 Takes in a string command of type "COMMAND DIGIT COMMAND DIGIT" and performs this action
 on our workspace container */
 void evaluateCommand(const std::string& s);

 /**<
  Where first and second are block numbers,
  puts block first onto block second after returning any blocks
  that are stacked on top of blocks first and second to their initial positions. */
 void Move_Onto(int first, int second);
 /**<
 Where first and second are block numbers,
 puts block first onto the top of the stack containing block second,
 after returning any blocks that are stacked on top of block first to their initial positions.  */
 void Move_Over(int first, int second);
 /**<
  Where first and second are block numbers,
  moves the pile of blocks consisting of block first,
  and any blocks that are stacked above block first, onto block second.
  All blocks on top of block second are moved to their initial positions prior to the pile taking place.
  The blocks stacked above block first retain their order when moved.  */
 void Pile_Onto(int first, int second);
 /**<
 Where first and second are block numbers,
 puts the pile of blocks consisting of block first,
 and any blocks that are stacked above block first,
 onto the top of the stack containing block second.
 The blocks stacked above block first retain their original order when moved.  */
 void Pile_Over(int first, int second);

 private:
 bool is_valid(unsigned int n);
 pIT find_IT(int a, int& pos);
 piles workspace;
};// end of struct pilestruct

int main()
{
    std::string temp;
    std::list<std::string> commands;
    int mmm = 0;
    while(mmm < 1 || mmm > 24)
    {
      std::string input;
      std::cin >> input;
      mmm = atoi(input.c_str());
    }
     pilestruct robotic(mmm);
    while(getline(std::cin,temp))
    {
      if(temp == "quit")
      {
        break;
      }
      commands.push_back(temp);
    }
    for(std::list<std::string>::iterator it = commands.begin(); it != commands.end(); ++it)
    {
     robotic.evaluateCommand(*it);
    }
    robotic.PrintStats();
    return 0;
}

/** \brief
 * struct class to work with the problem set 101 from
 * http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=3&page=show_problem&problem=37
 */
struct pilestruct
{
 public:
 pilestruct(unsigned int max_piles)
 {
 /** \brief
  * Creates max_piles piles with 1 block each. Numbering the Blocks from a to 1
  * \param max_piles number of Piles created
  */
  while(max_piles != 0)
  {
    workspace.push_back(stacky(1,--max_piles));
  }
 }
 /**< Will print the current pile compositions */
 void PrintStats()
 {
   int on = 0;
   for(piles::reverse_iterator it = workspace.rbegin(); it != workspace.rend(); it++)
   {
     std::cout << on++ << ":";
     for(stIT kk = (*it).begin(); kk != (*it).end(); kk++)
     {
      std::cout << " " << *kk;
     }
     std::cout << std::endl;
   }
 }
 /**<
 takes in a string command of type "COMMAND DIGIT COMMAND DIGIT" and performs this action
 on our workspace container
 */
 void evaluateCommand(const std::string& s)
 {
 // is it the move command?
 cchIT it = s.begin()+4;
 std::string temp(s.begin(), it);
 if(!temp.compare("move"))
 {
  // is it a number?
  while(isspace(*it) && it != s.end())
  {
    ++it;
  }
  cchIT cap = it;
  ++cap;
  while(!isspace(*cap) && it != s.end())
  {
    ++cap;
  }
  temp = std::string(it, cap);
  int a = atoi(temp.c_str());
  if(is_valid(a))
  {
    while(isspace(*cap) && it != s.end())
    {
      ++cap;
    }
    it = cap;
    while(!isspace(*cap) && it != s.end())
    {
      cap++;
    }

    temp = std::string(it, cap);
   if(!temp.compare("onto"))
   {
       // is it a number?
    while(isspace(*cap) && cap != s.end())
    {
      ++cap;
    }
    it = cap;
    ++cap;
    while(!isspace(*cap) && cap != s.end())
    {
      ++cap;
    }
    temp = std::string(it, cap);
    int b = atoi(temp.c_str());
    if(is_valid(b))
    {
      if(a == b) // illegal command
        {return;}
      Move_Onto(a,b);
    }
   }else
   if(!temp.compare("over"))
   {
       // is it a number?
    while(isspace(*it) && cap != s.end())
    {
      ++it;
    }
    it = cap;
    ++cap;
    while(!isspace(*cap) && cap != s.end())
    {
      ++cap;
    }
    temp = std::string(it, cap);
    std::cout << temp << std::endl;
    int b = atoi(temp.c_str());
    if(is_valid(b))
    {
      if(a == b) // illegal command
        {return;}
      Move_Over(a,b);
    }
   }

   else // not a valid command
    {return;}
  }// is not a number:
  else{return;}
  // successful move

 }// is it the pile command?
 else if(!temp.compare("pile"))
 {
  // is it a number?
  while(isspace(*it) && it != s.end())
  {
    ++it;
  }
  cchIT cap = it;
  ++cap;
  while(!isspace(*cap) && cap != s.end())
  {
    ++cap;
  }
  temp = std::string(it, cap);
  int a = atoi(temp.c_str());
  if(is_valid(a))
  {
    while(isspace(*cap) && cap != s.end())
    {
      ++cap;
    }
    it = cap;
    while(!isspace(*cap) && cap != s.end())
    {
      cap++;
    }

    temp = std::string(it, cap);
   if(!temp.compare("onto"))
   {
       // is it a number?
    while(isspace(*it) && it != s.end())
    {
      ++it;
    }
    it = cap;
    ++cap;
    while(!isspace(*cap) && cap != s.end())
    {
      ++cap;
    }
    temp = std::string(it, cap);
    int b = atoi(temp.c_str());
    if(is_valid(b))
    {
      if(a == b) // illegal command
        {return;}
      Pile_Onto(a,b);
    }
   }else
   if(!temp.compare("over"))
   {
       // is it a number?
    while(isspace(*it) && it != s.end())
    {
      ++it;
    }
    it = cap;
    ++cap;
    while(!isspace(*cap) && cap != s.end())
    {
      ++cap;
    }
    temp = std::string(it, cap);
    int b = atoi(temp.c_str());
    if(is_valid(b))
    {
      if(a == b) // illegal command
        {return;}
      Pile_Over(a,b);
    }
   }
   else // not a valid command
    {return;}
  }// is not a number:
  else{return;}

  // successful move

 }// successful pile command
 }

 private:
 bool is_valid(unsigned int n)
 {
  if(n >= 0 && n < workspace.size())
  {
    return true;
  }
  return false;
 }
 pIT find_IT(int a, int& pos)
 {
  for(pIT it = workspace.begin(); it!= workspace.end(); ++it)
  {
   pos = 0;
    for(stIT kk = it->begin(); kk != it->end(); ++kk)
    {
      if(*kk == a)
      {
        return it;
      }
      ++pos;
    }
  }
  return workspace.end();
  } // end of piles::it find_IT(i,i)

 /**<
  Where first and second are block numbers,
  puts block first onto block second after returning any blocks
  that are stacked on top of blocks first and second to their initial positions. */
 void Move_Onto(int first, int second)
 {
  if(first==second)
  {
    return;
  }
  int pos_a = 0;
  int pos_b = 0;
  pIT pile_a = find_IT(first,pos_a);
  if(pile_a == workspace.end())
  {
    return;
  }
  pIT pile_b = find_IT(second,pos_b);
  if(pile_b == workspace.end())
  {
    return;
  }
  if(pile_a == pile_b)
  {
    return;
  }
  stIT temp_b = pile_b->begin();
  advance(temp_b,pos_b+1);
  stIT temp_a = pile_a->begin();
  advance(temp_a,pos_a);
  stIT temp_a_after = temp_a;
  advance(temp_a_after,1);
  pile_b->insert(temp_b,temp_a,temp_a_after);


  pile_a->erase(temp_a);
 }// end of v Move_Onto(i,i)
 /**<
 Where first and second are block numbers,
 puts block first onto the top of the stack containing block second,
 after returning any blocks that are stacked on top of block first to their initial positions.  */
 void Move_Over(int first, int second)
 {
  if(first==second)
  {
    return;
  }
  int pos_a = 0;
  int pos_b = 0;
  pIT pile_a = find_IT(first,pos_a);
  if(pile_a == workspace.end())
  {
    return;
  }
  pIT pile_b = find_IT(second,pos_b);
  if(pile_b == workspace.end())
  {
    return;
  }
  if(pile_a == pile_b)
  {
    return;
  };
  stIT temp_a = pile_a->begin();
  advance(temp_a,pos_a);
  stIT temp_a_after = temp_a;
  advance(temp_a_after,1);
  pile_b->insert(pile_b->end(),temp_a,temp_a_after);


  pile_a->erase(temp_a);
 }// end of v Move_Over(i,i)
 /**<
  Where first and second are block numbers,
  moves the pile of blocks consisting of block first,
  and any blocks that are stacked above block first, onto block second.
  All blocks on top of block second are moved to their initial positions prior to the pile taking place.
  The blocks stacked above block first retain their order when moved.  */
 void Pile_Onto(int first, int second)
 {
  if(first==second)
  {
    return;
  }
  int pos_a = 0;
  int pos_b = 0;
  pIT pile_a = find_IT(first,pos_a);
  if(pile_a == workspace.end())
  {
    return;
  }
  pIT pile_b = find_IT(second,pos_b);
  if(pile_b == workspace.end())
  {
    return;
  }
  if(pile_a == pile_b)
  {
    return;
  }

  stIT temp_b_after = pile_b->begin();
  advance(temp_b_after,pos_b+1);

  stIT temp_a = pile_a->begin();
  advance(temp_a,pos_a);
  pile_b->insert(temp_b_after,temp_a,pile_a->end());

  pile_a->erase(temp_a,pile_a->end());
 }// end of v Pile_Onto(i,i)
 /**<
 Where first and second are block numbers,
 puts the pile of blocks consisting of block first,
 and any blocks that are stacked above block first,
 onto the top of the stack containing block second.
 The blocks stacked above block first retain their original order when moved.  */
 void Pile_Over(int first, int second)
 {
  if(first==second)
  {
    return;
  }
  int pos_a = 0;
  int pos_b = 0;
  pIT pile_a = find_IT(first,pos_a);
  if(pile_a == workspace.end())
  {
    return;
  }
  pIT pile_b = find_IT(second,pos_b);
  if(pile_b == workspace.end())
  {
    return;
  }
  if(pile_a == pile_b)
  {
    return;
  }
  stIT temp_a = pile_a->begin();
  advance(temp_a,pos_a);
  pile_b->insert(pile_b->end(),temp_a,pile_a->end());

  pile_a->erase(temp_a,pile_a->end());
 }// end of v Pile_Over(i,i)

 piles workspace;
 };
