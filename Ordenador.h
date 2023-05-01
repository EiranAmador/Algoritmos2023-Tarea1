#ifndef Ordenador_h
#define Ordenador_h

class Ordenador{
	private:
    // Defina aquí los métodos auxiliares de los algoritmos de ordenamiento solamente.
    // Puede definir cuantos métodos quiera.
	void cambiar(int *x, int *y)
	{
		int temp = *x;
		*x = *y;
		*y = temp;
	};

	void merge(int *A, int p, int q, int r)
	{
		// Create L ← A[p..q] and M ← A[q+1..r]
		int n1 = q - p + 1;
		int n2 = r - q;

		int L[n1], M[n2];

		for (int i = 0; i < n1; i++)
			L[i] = A[p + i];
		for (int j = 0; j < n2; j++)
			M[j] = A[q + 1 + j];

		// Maintain current index of sub-arrays and main array
		int i = 0;
		int j = 0;
		int k = p;

		// Until we reach either end of either L or M, pick larger among
		// elements L and M and place them in the correct position at A[p..r]
		while (i < n1 && j < n2) {
			if (L[i] <= M[j]) {
				A[k] = L[i];
				i++;
			} else {
				A[k] = M[j];
				j++;
			}
			k++;
		}

		// When we run out of elements in either L or M,
		// pick up the remaining elements and put in A[p..r]
		while (i < n1) {
			A[k] = L[i];
			i++;
			k++;
		}

		while (j < n2) {
			A[k] = M[j];
			j++;
			k++;
		}
	}

	void mergeSort(int *A, int p, int r)
	{
		if (p >= r)
        	return;
	
		int q = (p+r) / 2;
		mergeSort(A, p, q);
		mergeSort(A, q + 1, r);
		merge(A, p, q, r);
	};

	public:
	Ordenador(){};
	~Ordenador(){};
    // Si no implementa algunos de los métodos de ordenamiento no lo borre;
    // déjelo con el cuerpo vacío para evitar errores de compilación, ya
    // que se va a ejecutar el mismo «main» para todas las tareas.
    // Implemente los algoritmos en este archivo, no en un CPP.
	void seleccion(int *A, int n)
	{
		int i, j, lim;
		for (i = 0; i < n-1; i++)
		{
			lim = i;

			for (j = i+1; j < n; j++)
			{
			if (A[j] < A[lim])
				lim = j;
			}

			if (lim!=i)
				cambiar(&A[lim], &A[i]);
		}
	};
	void insercion(int *A, int n)
	{
		int j, lim;
		for (int i = 1; i < n; i++)
		{
			lim = A[i];
			j = i - 1;
	
			while (j >= 0 && A[j] > lim)
			{
				A[j + 1] = A[j];
				j = j - 1;
			}
			A[j + 1] = lim;
		}
	};
	void mergesort(int *A, int n)
	{
		mergeSort(A, 0, n-1);
	};
	void heapsort(int *A, int n);
	void quicksort(int *A, int n);
	void radixsort(int *A, int n);
};
#endif
