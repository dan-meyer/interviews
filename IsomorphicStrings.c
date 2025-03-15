#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <assert.h>

// from https://leetcode.com/problems/isomorphic-strings

//Given two strings s and t, determine if they are isomorphic.

//Two strings s and t are isomorphic if the characters in s can be replaced to get t.

//All occurrences of a character must be replaced with another character while preserving
// the order of characters.No two characters may map to the same character, but a character
// may map to itself.

//1 <= s.length <= 5 * 10^4
//t.length == s.length
//s and t consist of any valid ascii character.

#define isIsomorphic isIsomorphic2

enum bool { true, false };

#define ARRAY1_MAP 0
#define ARRAY2_MAP 1

enum bool isIsomorphic1(char* s, char* t) {

	char mapping[256][2]; // [][0] is for s char and [][1] is for t char

	memset(mapping, 0, sizeof(mapping));

	for (int i = 0; i < strlen(s); i++) {
		if ((mapping[s[i]][ARRAY1_MAP] == '\0') && ((mapping[t[i]][ARRAY2_MAP] == '\0'))) { // new letter to map
			mapping[s[i]][ARRAY1_MAP] = t[i];
			mapping[t[i]][ARRAY2_MAP] = s[i];
		}
		else if ((mapping[s[i]][ARRAY2_MAP] != t[i]) && (mapping[t[i]][ARRAY2_MAP] != s[i])) { // isomorphic check failed because the letter is different
			return false;
		}
	}

	return true;
}

char dict[256][2];

enum bool addDict(char char1, char char2) {

	// if this entry has never been initialized
	if (((dict[char1][ARRAY1_MAP] == 0) || (dict[char1][ARRAY1_MAP] == char2))
		&& ((dict[char2][ARRAY2_MAP] == 0) || (dict[char2][ARRAY2_MAP] == char1))) {
		dict[char1][0] = char2;
		dict[char2][1] = char1;
		return true;
	}
	return false;
}

enum bool isIsomorphic(char* s, char* t) {

	int stringLen = strlen(s);
	enum bool dictResult;

	memset(dict, 0, sizeof(dict));

	for (int i = 0; i < stringLen; i++) {
		dictResult = addDict(s[i], t[i]);
		if (dictResult == false) {
			return false;
		}
	}

	return true;
}

void main() {

	char s1[] = "egg";
	char t1[] = "add";

	printf("%s and %s are isomorphic = %s\n", s1, t1, (isIsomorphic(s1, t1) == true) ? "yes" : "no");

	char s2[] = "foo";
	char t2[] = "bar";

	printf("%s and %s are isomorphic = %s\n", s2, t2, (isIsomorphic(s2, t2) == true) ? "yes" : "no");

	char s3[] = "paper";
	char t3[] = "title";

	printf("%s and %s are isomorphic = %s\n", s3, t3, (isIsomorphic(s3, t3) == true) ? "yes" : "no");

	char s4[] = "badc";
	char t4[] = "baba";

	printf("%s and %s are isomorphic = %s\n", s4, t4, (isIsomorphic(s4, t4) == true) ? "yes" : "no");

	char s5[] = "13";
	char t5[] = "42";

	printf("%s and %s are isomorphic = %s\n", s5, t5, (isIsomorphic(s5, t5) == true) ? "yes" : "no");
}