class cycle {
	public void escape(int n) {
		if(n == 10) {
			if(cycle_lib.jump(3) == true) {
				cycle_lib.jump(2);
				cycle_lib.jump(3);
				cycle_lib.jump(1);
				cycle_lib.jump(6);
			}
		}
	}
}
