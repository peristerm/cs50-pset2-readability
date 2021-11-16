#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

int main(void)
{
    int counter1 = 0;
    int counter2 = 0;
    int counter3 = 0;
    float L;
    float S;
    float index;

    //get the text from the user
    string a = get_string("Text:");


    //count the letters
    for (int i = 0, n = strlen(a); i < n; i++)
    {
        if (a[i] >= 'a' && a[i] <= 'z')

        {

            counter1++;

        }
        else if (a[i] >= 'A' && a[i] <= 'Z')
        {
            counter1++;
        }

        //count the words

        else if (a[i] == ' ')
        {
            counter2++;

        }

        //count the sentences

        else if (a[i] == '.' || a[i] == '?' || a[i] == '!')
        {
            counter3++;
        }

    }

    //Calculate Coleman-Liau index
    L = (100 * (float) counter1) / (counter2 + 1);

    S = (100 * (float) counter3) / (counter2 + 1);

    index = 0.0588 * L - 0.296 * S - 15.8;

    //define the grades
    if (index < 1)
    {
        printf("Before Grade 1\n");
    }

    else if (index > 16)
    {
        printf("Grade 16+\n");
    }

    else
    {
        printf("Grade %.0f\n", round(index));
    }

}












