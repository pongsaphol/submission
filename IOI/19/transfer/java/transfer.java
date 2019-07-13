
class transfer {
	
	int[] get_attachment(int[] source) {
		return new int[] { 0, 1, 0 };
	}
	
	int[] retrieve(int[] data) {
		return java.util.Arrays.copyOfRange(data, 0, data.length-3);
	}
	
}
