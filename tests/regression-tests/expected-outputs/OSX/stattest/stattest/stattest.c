int main(int argc, char *argv[]);


/** address: 0x00001ce0 */
int main(int argc, char *argv[])
{
    int g3; 		// r3
    int g3_1; 		// r3
    struct stat local0; 		// m[g1 - 128]
    int local1; 		// m[g1 - 80]

    g3_1 = stat("test/source/stattest.c", &local0);
    printf("Stat returns %d; size of file is %d\n", g3_1, local1);
    return g3;
}

