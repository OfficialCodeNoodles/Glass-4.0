#pragma once

// Dependencies 
#include "../typedef.hpp" 
 
namespace gs {
	namespace util {
		///////////////////////////////////////////////////////////
		/// class Clock is a timing class that can be used to 
		/// achieve a constant framerate. 
		///////////////////////////////////////////////////////////
		class GLASS_EXPORT Clock {
		public:
			/// Alias for std::chrono::high_resolution_clock::time_point. 
			typedef std::chrono::high_resolution_clock::time_point TimePoint;
			/// Alias for std::chrono::duration<float, std::milli>. 
			typedef std::chrono::duration<float, std::milli> Duration;

			Clock();
			~Clock();

			///////////////////////////////////////////////////////////
			/// Method begin() will start the Clock. Note: To stop the 
			/// clock call end() and then call wait() to wait until a 
			/// certain framerate has been achieved. 
			///////////////////////////////////////////////////////////
			virtual void begin();
			///////////////////////////////////////////////////////////
			/// Method end() will stop the Clock. Note: Call wait() 
			/// afterwards to wait until a certain framerate has been 
			/// achieved. 
			///////////////////////////////////////////////////////////
			virtual void end();
			///////////////////////////////////////////////////////////
			/// Method wait() will sleep on the current thread until 
			/// a certain framerate has been achieved. Note: This will
			/// only work correctly if begin() and end() have been 
			/// called and called correctly. 
			///////////////////////////////////////////////////////////
			virtual void wait(unsigned int framerate);

			///////////////////////////////////////////////////////////
			/// @returns float: Frame rate after last wait() call. 
			///////////////////////////////////////////////////////////
			virtual float getFrameRate() const;
			///////////////////////////////////////////////////////////
			/// @returns float: Frame rate if uncapped from last wait()
			///  call. 
			///////////////////////////////////////////////////////////
			virtual float getUncappedFrameRate() const;
		protected:
			/// Points in time that the clock measure. 
			TimePoint S, E;
			/// The difference in milliseconds between TimePoint's. 
			Duration difference;
			/// Internal stored framerates. 
			float currentFrameRate, currentUncappedFrameRate;

			///////////////////////////////////////////////////////////
			/// Method framesToMilliseconds() will convert a given 
			/// amount of frames per second into the amount of 
			/// milliseconds that are equal. 
			/// @param unsigned int framerate: Number of frames to
			///  convert. 
			/// @returns float: Duration in milliseconds. 
			///////////////////////////////////////////////////////////
			virtual float framesToMilliseconds(unsigned int framerate);
			///////////////////////////////////////////////////////////
			/// Method millisecondsToFrames() will convert a given 
			/// duration in milliseconds into franes per second. 
			/// @param float duration: Duration in milliseconds. 
			/// @returns float: Frames per second. 
			///////////////////////////////////////////////////////////  
			virtual float millisecondsToFrames(float duration);
		};
	}
}