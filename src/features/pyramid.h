#include "../Util/common.h"

using namespace cv;
#include "chnsCompute/Channel.h"

class Pyramid{
public:
	Pyramid(){
		//colorspace=mana.getcolorspace();
		colorspace=1;
		
		nPerOct=8;
		nOctUp=0;
		nApprox=-1;
		pad.height=0;
		pad.width=0;
		minDs.height=16;
		minDs.width=16;
		smooth=1;
		concat=true;
		complete=true;
	}
	Pyramid(ChnsManager& c):Pyramid(){}
	~Pyramid(){}
	void computeData(Mat image,vector<vector <Mat*> >& data);
	//get methods
	
	int getcolorspace()
	{
		return colorspace;
	}
	int getnPerOct()
	{
		return nPerOct;
	}
	int getnOctUp()
	{
		return nOctUp;
	}
	int getnApprox()
	{
		return nApprox;
	}
	Size getpad()
	{
		return pad;
	}
	Size getminDs()
	{
		return minDs;
	}
	int getsmooth()
	{
		return smooth;
	}
	bool getconcat()
	{
		return concat;
	}
	bool getcomplete()
	{
		return complete;
	}
	//set methods
	void getcolorspace(int colors)
	{
		colorspace=colors;
	}
	void setconcat(bool c)
	{
		concat=c;
	}
	void setcomplete(bool c)
	{
		complete=c;
	}
	void setsmooth(int sm)
	{
		smooth=sm;
	}
	void setnPerOct(int p)
	{
		nPerOct=p;
	}
	
	void setnOctUp(int s)
	{
		nOctUp=s;
	}
	void setpad(Size p)
	{
		pad=p;
	}
	void setminDs(Size mins)
	{
		minDs=mins;
	}
private:

	
	int colorspace;
	int nPerOct;      // [8] number of scales per octave
	int nOctUp;       // [0] number of upsampled octaves to compute
	int nApprox;      //[-1] number of approx. scales (if -1 nApprox=nPerOct-1)
//	float* lambdas;      // [] coefficients for power law scaling (see BMVC10)
	Size pad;          // [0 0] amount to pad channels (along T/B and L/R)
	Size minDs;        // [16 16] minimum image size for channel computation
	int smooth;       //[1] radius for channel smoothing (using convTri)
	bool concat;       //[1] if true concatenate channels
	bool complete;     // [] if true does not check/set default vals in pPyramid

};


//class pyramid{
//public:
//	pyramid(pPyramid pyramid_ppyramid,int ntypes,int nscales){
//
//	}
//	pyramid(){}
//	~pyramid(){}
//private:
//	pPyramid pyramid_pPyramid;

//	data* pyramid_data;         // [nScales x nTypes] cell array of computed channels
//	info* pyramid_info;      // [nTypes x 1] struct array (mirrored from chnsCompute)
//	float* lambdas;     //[nTypes x 1] scaling coefficients actually used
//	float* scales;       //[nScales x 1] relative scales (approximate)
//	//int()(2) scaleshw     - [nScales x 2] exact scales for resampling h and w
//};
//
