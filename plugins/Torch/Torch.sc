Torch : UGen {
	*ar { |input, temperature|
		/* TODO */
		^this.multiNew('audio', input, temperature);
	}
	checkInputs {
		/* TODO */
		^this.checkValidInputs;
	}
}
