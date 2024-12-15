#include <map>
#include <vector>
#include <string>
#include <iostream>
#include <stack>
#include "Operations.h"

using namespace std;

map<string, int> syb_table;

// heper functions
bool isOperator(const string &token)
{
    const string operators[] = {"+", "-", "*", "/", "%", ">", "<", ">=", "<=", "==", "!=", "&&", "||", "!", "~"};
    for (const string op : operators)
    {
        if (token == op)
            return true;
    }
    return false;
}

int applyOperator(const string &op, int a, int b)
{
    if (op == "+")
        return a + b;
    if (op == "-")
        return a - b;
    if (op == "*")
        return a * b;
    if (op == "/")
        return b != 0 ? a / b : 0; // Can't divide by 0
    if (op == "%")
        return a % b;
    if (op == ">")
        return a > b;
    if (op == "<")
        return a < b;
    if (op == ">=")
        return a >= b;
    if (op == "<=")
        return a <= b;
    if (op == "==")
        return a == b;
    if (op == "!=")
        return a != b;
    if (op == "&&")
        return a && b;
    if (op == "||")
        return a || b;
    if (op == "!")
        return !a;
    if (op == "~")
        return -a;
    return 0;
}

// end of helper functions

int postFix(vector<string> &blip)
{
    // Evaluate the postfix expression using a stack
    stack<int> operandStack;

    for (auto it = blip.rbegin(); it != blip.rend(); ++it)
    { // Reverse iterate for prefix notation
        const string &token = *it;

        if (isdigit(token[0]))
        { // Push numbers onto the stack
            operandStack.push(stoi(token));
        }
        else if (syb_table.find(token) != syb_table.end()) // Check for variable
        {
            operandStack.push(syb_table[token]);
        }
        else if (isOperator(token))
        { // Apply operators to operands
            if (token == "!" || token == "~")
            {
                int a = operandStack.top();
                operandStack.pop();
                operandStack.push(applyOperator(token, a, 0));
            }
            else if (operandStack.size() < 2)
            {
                cout << "Error: operator '" << token << "'" << endl;
                return 0;
            }
            else
            {
                int a = operandStack.top();
                operandStack.pop();
                int b = operandStack.top();
                operandStack.pop();
                int result = applyOperator(token, a, b);
                operandStack.push(result);
                if (blip.size() < 2)
                    break;
            }
        }
    }
    if (operandStack.size() != 1)
    {
        //  cout << "Error: leftover operands in stack" << endl;
        return 0;
    }
    blip.clear();
    return operandStack.top();
}

int polishExpression(string op)
{
    vector<string> blip; // store expression
    while (true)
    {
        // Read and validate the next token

        string value = next_token();
        string next = peek_next_token();

        if (value.empty() || next_token_type == NAME || next_token_type == END)
        {
            if (syb_table.find(next) != syb_table.end() && isOperator(op))
            {
                blip.push_back(op);
                blip.push_back(next);
            }
            else if (isdigit(op[0]) && blip.size() < 1)
            {
                blip.push_back(op);
                // break;
            }
            
            next = peek_next_token();
            break;
        }
        if (value[0] == '/' && value[1] == '/')
        {
            skip_line(); // skip comments
            next = peek_next_token();
            if(next[0] == '/' && next[1] == '/') break;
            continue;
        }
        else
        {
            if (isOperator(op))
            {
                blip.push_back(op);
                // read_next_token();
                op = 'y';
            }
            else if (isOperator(value))
            {
                blip.push_back(value);
                string nxtValue = peek_next_token();
                read_next_token();
                nxtValue = peek_next_token();
                if ((next[0] == '/' && next[1] == '/')|| nxtValue == "//" || nxtValue == "text" || peek_next_token()[0] == '\n' || peek_next_token()[0] == '\0')
                {
                    // blip.push_back(value);
                    break;
                }
                continue;
            }
            blip.push_back(value);
              if(next[0] == '/' && next[1] == '/') break;
        }

        string nxtValue = peek_next_token();
        read_next_token();
        nxtValue = peek_next_token();
        if (nxtValue == "//" || nxtValue == "text" || peek_next_token()[0] == '\n' || peek_next_token()[0] == '\0')
        {
            // blip.push_back(value);
            break;
        }
    }
    return postFix(blip);
}

int updateExpression()
{
    vector<string> blip; // store expression
    while (true)
    {
        // Read and validate the next token
        read_next_token();
        const char *chr = next_token();
        string value = next_token();
        char nxt = peek_next_token()[0];

        if (value.empty() || next_token_type == END)
        {
            break;
        }
        if (value[0] == '/' && value[1] == '/')
        {
            skip_line(); // skip comments
                         // break;
            continue;
        }

        if (syb_table.find(value) != syb_table.end())
        {
            blip.push_back(value);
            if (next_token_type == NAME)
            {
                read_next_token();
                value = next_token();
                if (syb_table.find(value) != syb_table.end())
                    blip.push_back(value);
                break;
            }
        }
        if (next_token_type == NUMBER || next_token_type == SYMBOL)
        {
            if (syb_table.find(value) != syb_table.end())
            {
                read_next_token();
                value = next_token();
            }
            blip.push_back(value);
            value = peek_next_token()[0];
            if (next_token_type == NAME)
            {
                if (syb_table.find(value) != syb_table.end())
                    blip.push_back(value);
                break;
            }
        }
        else if (isOperator(value))
        {
            blip.push_back(value);
        }
        else
        {
            nxt = peek_next_token()[0];
            break;
        }
    }
    return postFix(blip);
}

void run()
{
    string txt = "text";
    string out = "output";
    string v = "var";
    string s = "set";

    while (next_token_type != END)
    {

        read_next_token();
        const char *chr = next_token();
        string token = next_token();
        string nxt = peek_next_token();

        if (token.empty())
            continue;
        if (token[0] == '/' && token[1] == '/')
        {
            skip_line();
            read_next_token();
            
             nxt = peek_next_token();
            continue;
        }
         if (nxt[0] == '/' && nxt[1] == '/')
            {
                skip_line();
                read_next_token();
                 nxt = peek_next_token();
            continue;                              
            }
            
        if (token == txt)
        { // text declaration
            read_next_token();
            token = next_token();
            cout << token;
            // continue;
        }
        else if (token == v)
        { // Variable declaration
            read_next_token();
            token = next_token();
            nxt = peek_next_token();
            if (syb_table.find(token) != syb_table.end())
            {
                cout << "Error: Variable '" << token << "' already declared" << endl;
                read_next_token();
                string val = next_token();
                int var = polishExpression(val);
                syb_table[token] = var;
            }
            else
            {
                read_next_token();
                string val = next_token();
                int var = polishExpression(val);
                syb_table[token] = var;
            }
            nxt = peek_next_token();
            continue;
        }
        else if (token == s)
        { // Set variable
            read_next_token();
            string syb = next_token();
            int newValue = updateExpression();
            nxt = peek_next_token();
            if (syb_table.find(syb) == syb_table.end())
            {
                cout << "Error: Variable '" << syb << "' not declared" << endl;
                syb_table[syb] = newValue;
            }
            else
            {
                syb_table[syb] = newValue;
            }
            continue;
        }
        else if (token == out)
        { // handle out
            read_next_token();
            token = next_token();
            nxt = peek_next_token();

            if (isOperator(token)) // check
            {
                string op = token;
                int val = polishExpression(op);
                cout << val;
            }
            else if (isdigit(token[0])) // check
            {
                cout << token;
            }
            else if (syb_table.find(token) != syb_table.end()) // check
                cout << syb_table[token];
            else
            {
                cout << "Error: Variable '" << token << "' not declared" << endl;
            }
        }
        nxt = peek_next_token();
        
    }
    syb_table.clear();
}
