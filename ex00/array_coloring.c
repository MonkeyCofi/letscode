#include <stdio.h>
#include <stdlib.h>

void	print_array(char **array, int length);
int same_parity(int a, int b);
int	add_array(int *array, int length);

int main(void)
{
	// array of strings to store yes or no after each test
	char	**results;
	int		*array;
	int		i;
	int		test_cases;
	int		n;
	int		j;

	test_cases = 0;
	i = 0;
	n = 0;
	// request for number of test cases
	printf("Enter number of test cases: ");
	scanf("%d", &test_cases);
	// allocate memory for length of string array
	results = malloc(sizeof(char *) * test_cases);

	while (i < test_cases)
	{
		// getting the length of the array
		printf("Enter the number of elements within array: ");
		scanf("%d", &n);
		// allocate memory for the array
		array = malloc(sizeof(int) * n);
		results[i] = malloc(sizeof(char) * 4);
		
		j = 0;
		while (j < n)
		{
			printf("Enter array element: ");
			scanf("%d", &array[j]);
			j++;
		}
		if (add_array(array, n))
			results[i] = "YES";
		else
			results[i] = "NO";
		i++;
	}
	print_array(results, test_cases);
}

void	print_array(char **array, int length)
{
	int	i;

	i = 0;
	while (i < length)
	{
		if (i == length - 1)
			printf("%s\n", array[i]);
		else
			printf("%s, ", array[i]);
		i++;
	}
}

int same_parity(int a, int b)
{
	if ((a % 2 == 0 && b % 2 == 0) || (a % 2 == 1 && b % 2 == 1))
		return (1);
	return (0);
}

int	add_array(int *array, int length)
{
	int	*ret;
	int	i;
	int	first_sum;
	int	second_sum;

	ret = malloc(sizeof(int) * 2);
	i = first_sum = second_sum = 0;
	// add the numbers of the array up to length / 2 elements
	while (i < length / 2)
	{
		first_sum += array[i];
		i++;
	}
	i = length / 2;
	while (i < length)
	{
		second_sum += array[i];
		i++;
	}
	if (same_parity(first_sum, second_sum))
		return (1);
	return (0);
}
