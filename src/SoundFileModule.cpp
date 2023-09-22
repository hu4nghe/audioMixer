/*
	std::string filePathStr;
	while (true)
	{
		if(NDIReady.load())
		{
			std::print("Sndfile: Please enter the path of the sound file: ");
			std::getline(std::cin >> std::ws, filePathStr);
			break;
		}
	}*/

SndfileHandle sndFile("C:/Users/Modulo/Desktop/Nouveau dossier/Music/Rachmaninov- Music For 2 Pianos, Vladimir Ashekenazy & André Previn/Rachmaninov- Music For 2 Pianos [Disc 1]/Rachmaninov- Suite #2 For 2 Pianos, Op. 17 - 3. Romance.wav");
const size_t bufferSize = sndFile.frames() * sndFile.channels() + 100;

float* temp = new float[bufferSize];

SNDdata.setCapacity(bufferSize);

sndFile.read(temp, bufferSize);
SNDdata.push(temp, sndFile.frames(), sndFile.channels(), sndFile.samplerate());

delete[] temp;
return;