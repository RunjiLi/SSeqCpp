#include<vector>
#include<array>
#include<iostream>

const int CACHE_SIZE = 193;
const int MATRIX_SIZE = 7;
const int MAX_DEGREE = 276;

std::array<std::array<bool, MATRIX_SIZE>, MATRIX_SIZE> generate_matrix(const  std::array<int, MATRIX_SIZE>& seq)
{
	std::array<std::array<bool, MATRIX_SIZE>, MATRIX_SIZE> matrix = { 0 };
	for (int i = 0; i < MATRIX_SIZE; ++i)
	{
		if (seq[i] > 0)
		{
			matrix[i + 1 - seq[i]][seq[i] - 1] = 1;
		}
	}
	return matrix;
}

/**
The procedure that generates cache for computing Milnor basis
@param cache : stores the generated cache, should be initialized to an array of empty vectors
@param seq: auxlliary sequence for generating matrix
@param depth: depth for search, should input 1
*/
void generate_cache(std::array<std::vector<std::array<std::array<bool, MATRIX_SIZE>, MATRIX_SIZE> >, CACHE_SIZE>& cache, std::array<int, MATRIX_SIZE>& seq, int depth = 1)
{
	if (depth > MATRIX_SIZE)
	{
		int index = 0;
		int degree = 0;
		for (int i = 0; i < MATRIX_SIZE; ++i)
		{
			if (seq[i] > 0)
			{
				index += pow(2, i);
				degree += pow(2, i + 1)-1;
			}
		}
		if(degree<=MAX_DEGREE)
			cache[index].push_back(generate_matrix(seq));
		return;
	}
	for (int i = 0; i <= depth; ++i)
	{
		seq[depth-1] = i;
		generate_cache(cache, seq, depth + 1);
	}
	return;
}

void print_matrix(const std::array<std::array<bool, MATRIX_SIZE>, MATRIX_SIZE>& matrix)
{
	for (int j = 0; j < MATRIX_SIZE; ++j)
	{
	
		for (int k = 0; k < MATRIX_SIZE; ++k)
			std::cout <<matrix[j][k] << ' ';
		std::cout << std::endl;
	}
}

int main()
{

	std::array<std::vector<std::array<std::array<bool, MATRIX_SIZE>, MATRIX_SIZE> >, CACHE_SIZE> cache = { {} };
	std::array<int, MATRIX_SIZE> temp_seq;
	generate_cache(cache, temp_seq, 1);
	int sum = 0;
	for (int i = 0; i < CACHE_SIZE; ++i)
	{
		
		if (cache[i].size() > 0)
		{
			std::cout << "index" << i << ": " << cache[i].size() << " matrices" << std::endl;
			sum += cache[i].size();
			//for (std::array<std::array<int, MATRIX_SIZE>, MATRIX_SIZE> matrix : cache[i])
			//	print_matrix(matrix);
			std::cout << std::endl;
		}
	}
	std::cout << sum;
}

