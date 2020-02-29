#include <iostream>
#include <cmath>

using std::cout;
using std::cin;
using std::endl;

#define max_size 255


int gaussElim(double (&my_vect)[max_size], int size, double (&matrix)[max_size][max_size]){
	for(int i = 0; i < size-1; i++){
		if(fabs(matrix[i][i]) < 1e-6){
			return 0;
		}
		else{
			for(int j = i+1; j < size; j++){
				double mult = matrix[j][i]/matrix[i][i];
				for(int k = i; k < size; k++){
					matrix[j][k] = matrix[j][k] - mult*matrix[i][k];
				}
				my_vect[j] = my_vect[j] - mult*my_vect[i];
			}
		}
	}
			
	return 1;

}
void m_printout(double matrix[max_size][max_size], int m_size){
	for(int i = 0; i < m_size; i++){
		for(int j = 0; j < m_size; j++){
			cout << matrix[i][j] << " ";
		}
		cout << " " << endl;
	}
}

void v_printout(double vector[max_size], int v_size){
	for(int i = 0; i < v_size; i++){
		cout << vector[i] << " ";
	cout << " " << endl;
	}
}

void backsolve(int vector_size, double my_matrix[max_size][max_size], double my_vector[3], double (&final_soln)[max_size]){
        for(int i = vector_size-1; i > -1; i--){
        	for(int j = i; j < vector_size; j++){
                	my_vector[i] = my_vector[i] - my_matrix[i][j]*final_soln[j];
                }
                final_soln[i] = my_vector[i]/my_matrix[i][i];
        }
}
			
int main(){
	double new_data[max_size][max_size];
	cout << "Matrix row size: ";

	int f_size;
	cin >> f_size;
	
	cout << "Enter data going by column (e.g. 1 0 2 would be the first row of a 3x3 matrix) followed by hitting the enter key: " << endl;
	for(int i = 0; i < f_size; i++){
		for(int j = 0; j < f_size; j++){
			int curr_data;
			cin >> curr_data;
			new_data[i][j] = curr_data;
		}
	}
		
	cout << "A matrix: " << endl;
	m_printout(new_data, 3);

	double new_vector[max_size];

	cout << "Enter the b vector data: " << endl;
	for(int i = 0; i < f_size; i++){
		int vect_data;
		cin >> vect_data;
		new_vector[i] = vect_data;
	}

	cout << "b vector: " << endl;
	v_printout(new_vector, f_size);

	int code = gaussElim(new_vector, f_size, new_data);
	if(code){	
		cout << "Row reduced matrix: " << endl;
		m_printout(new_data, f_size);
		cout << "b vector: " << endl;
		v_printout(new_vector, f_size);
	}	
	else{
		cout << "Singular value of 0 detected!" << endl;
	}	

	double final_solution[max_size];
	backsolve(f_size, new_data, new_vector, final_solution);
	cout << "Solution to Ax = b: " << endl;
	v_printout(final_solution, f_size);

	return 0;

} 
