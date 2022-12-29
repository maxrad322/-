void sort(float data[], int indx[], int len) {

	float temp;

	for (int i = 0; i < len; i++) {
		indx[i] = i;
	}

	for (int i = 0; i < len - 1; i++) {
		for (int j = 0; j < len - 2; j++) {
			if (data[indx[j]] > data[indx[j + 1]]) {
				temp = indx[j];
				indx[j] = indx[j + 1];
				indx[j + 1] = temp;
			}
		}
	}

}




