#pragma once

public enum TILENAMES { LAVA, WALL, FLOOR, CORRIDOR, DOOR, HOLE, FOG };

ref class Cell
{
public:
	int TileIndex;
	bool Fog;

	Cell(int StartTileIndex, bool StartFog);

	bool GetFog() { return Fog; }
	int GetTileIndex() { return TileIndex; }
	void SetFog(bool FogSet) { Fog = FogSet; }
	void SetTileIndex(int TileIndexSet) { TileIndex = TileIndexSet; }
};

