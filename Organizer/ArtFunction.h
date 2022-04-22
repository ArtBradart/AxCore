#pragma once

class ArtFunction
{
public:
	ArtFunction() : _function(nullptr) {};
	~ArtFunction() { _function = nullptr; }

	void SetFunction(void(*function)(void)) { _function = function; }
	void Execute() { if(_function) return _function(); }

protected:
	void(*_function)(void);
};