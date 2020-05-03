import java.util.Scanner;
class Nukit
{
    static boolean[] [] [] [] winningPosition;
    static int[] [] moves = {{2, 1, 0, 2}, {1, 1, 1, 1}, {0, 0, 2, 1}, {0, 3, 0, 0}, {1, 0, 0, 1}};

    static boolean loosingPosition (int a, int b, int c, int d)
    {
	if (a < 0 || b < 0 || c < 0 || d < 0)
	    return false;
	else
	    return !winningPosition [a] [b] [c] [d];
    }

    public static void main (String[] args)
    {
    Scanner kb = new Scanner(System.in);
	int n, a, b, c, d;

	winningPosition = new boolean [31] [31] [31] [31];
	for (int i = 0 ; i < 31 ; i++)
	    for (int j = 0 ; j < 31 ; j++)
		for (int k = 0 ; k < 31 ; k++)
		    for (int l = 0 ; l < 31 ; l++)
			winningPosition [i] [j] [k] [l] = false;
	for (int i = 0 ; i < 31 ; i++)
	    for (int j = 0 ; j < 31 ; j++)
		for (int k = 0 ; k < 31 ; k++)
		    for (int l = 0 ; l < 31 ; l++)
			for (int m = 0 ; m < 5 ; m++)
			    if (loosingPosition (i - moves [m] [0], j - moves [m] [1], k - moves [m] [2], l - moves [m] [3]))
				winningPosition [i] [j] [k] [l] = true;
	n = kb.nextInt();
	for (int i = 0 ; i < n ; i++)
	{
	    a = kb.nextInt();
	    b = kb.nextInt();
	    c = kb.nextInt();
	    d = kb.nextInt();
	    if (winningPosition [a] [b] [c] [d])
		System.out.println ("Patrick");
	    else
		System.out.println ("Roland");
	}
    }
}