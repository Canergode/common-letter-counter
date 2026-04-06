#include <stdio.h>
#include <stdlib.h>

// Function to find the length of a word manually (without strlen)
void findLength(char word[],int *length)
{
    int i;
    i=0;
    while(word[i]!='\0')
    {
        i++;
    }
    *length=i;
}

// Function to count common letters between two words
// Ignores duplicate letters in the first words
void commonLetterCount(char w1[],char w2[],int *count)
{
    int i,j,k,isDuplicate;
    *count=0;

    for(i=0;w1[i]!='\0';i++)
    {
        // Check if this letter was already counted in w1
       isDuplicate=0;

       for(k=0;k<i;k++)
       {
           if(w1[i]==w1[k])
           {
               isDuplicate=1;
               break;
           }
       }
       // If not duplicate check if it exists in w2
        if(isDuplicate==0)
        {
            for(j=0;w2[j]!='\0';j++)
        {
            if(w1[i]==w2[j])
            {
                (*count)++;
                break;
            }
        }
        }

    }
}

int main()
{
    int length,commonCount;
    char word1[100];
    char word2[100];

    // Get two words from user
    printf("Enter the 1st word: ");
    scanf("%s",word1);

    printf("Enter the 2nd word: ");
    scanf("%s",word2);

    // Find length of first word
    findLength(word1,&length);

    // Count common letters
    commonLetterCount(word1,word2,&commonCount);

    // Print results
    printf("Length of the first word: %d\n",length);
    printf("Number of common letters: %d",commonCount);

    return 0;
}
