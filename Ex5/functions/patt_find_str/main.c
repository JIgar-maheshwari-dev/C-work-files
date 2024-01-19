/// @file main.c
#include<stdio.h>
#define MAXLINE 100 	///< MAXLINE variable for maximum string length



///This is getmyline function, to get line from user
/** @param [in] char array, max length
 *  @param [out] string length
 */
int getmyline(char line[],int max);


/** 
 * This is strindex, which returns the index at where it matches the pattern
 * @param [in] source string, pattern
 * @param [out] index where it find mathcing pattern
 */
int strindex(char source[],char patern[]);

///This is pattern that we are looking for in string
char pattern[]="jigar";

int main() {
	/**
	 * string for finding the patterm
	 */
	char string[MAXLINE];
	
	/// if found any pattern in string than it will be incremented
	int found=0;

	/**
	 * run this while loop until getmyline dosent return any negative number
	 *
	 */

	while (getmyline(string, MAXLINE) > 0)
		///if string index return any positive value than print that string and 
		//increment the found count
 		if (strindex(string, pattern) >= 0) {
 			printf("%s", string);
 			found++;
 		}

	return found;


}


/**
 * getmyline: get line into s, return length
 **/
int getmyline(char s[], int lim){

 	int c, i=0;
	
	/** If we string is in maxlength range and current character is not EOF and not end of file than add that to string
	 *
	 */

	while (--lim > 0 && (c=getchar()) != EOF && c != '\n')
 		s[i++] = c;
	
	///If it is new line than also add it at end
	if (c == '\n')
 		s[i++] = c;
	
	///At the end add null character for string termination
	s[i] = '\0';
	
	///return the length
	return i;

}



/* strindex: return index of t in s, -1 if none */

int strindex(char s[], char t[]){

 	int i, j, k;
 	for (i = 0; s[i] != '\0'; i++) {
 		for (j=i, k=0; t[k]!='\0' && s[j]==t[k]; j++, k++);

		if (k > 0 && t[k] == '\0')
	 return i;
 	}

 	return -1;

}



/**
 *
 * @mainpage This is the program for finding a pattern in a string
 * This is the main page for the project.
 * 1. Describe the project in general and the components/ modules it has
 * 2. Explain each module using data flow and software architecture diagrams
 * 3. Place links for each of the sub module's markdown pages
 * @page module_name
 * **Author:** Jigar Maheshwari
 * **Date:**  Jan 18 2024
 * ## Module's Role
 * Explain the module's role in the system in general
 **/

