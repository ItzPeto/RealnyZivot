// game helpers
native Float:MPDistanceCameraToLocation(Float:CamX, Float:CamY, Float:CamZ, Float:ObjX, Float:ObjY, Float:ObjZ, Float:FrX, Float:FrY, Float:FrZ); // calculates how distant target aim is from camera data pointed towards a certain point
native Float:MPGetVehicleUpsideDown(vehicleid); // returns values such as 1.0 as pointing up, -1.0 is totally upside down. returns -5.0 if car id is not 1..2000.
native MPGetAimTarget(PlayerID, Float:SeekRadius = 50.0); // returns player that this player is aiming at or invalid player id if no player in target area.
native MPGetTrailerTowingVehicle(vehicleid); // finds the vehicle that this trailer is attached to, returns invalid_vehicle_id if invalid or not attached to any towing vehicle.
native MPGetVehicleDriver(vehicleid); // gets vehicle driver id or invalid player id - does a quick reverse vehicle to player id lookup.
native MPGetVehicleDriverCount(vehicleid); // returns number of drivers a car has (important to solve 2 drivers 1 car issue - if you wrote any decent anticheat you know what i mean)
native MPGetVehicleOccupantCnt(vehicleid); // returns number of player a vehicle is carrying
native MPGetVehicleSurfersCnt(vehicleid); // returns number of players surfing a vehicle

native MPProjectPointOnVehicle(vehicleid, Float:v1x, Float:v1y, Float:v1z, &Float:resx, &Float:resy, &Float:resz, worldspace = 0); // projects a point on vehicle's rotation on all 3 axes.
native MPProjectPointOnPlayer(playerid, Float:v1x, Float:v1y, Float:v1z, &Float:resx, &Float:resy, &Float:resz); // projects a point on player's facing angle (x - sideways, y front/back, z = up/down).

// pure math
native Float:FMPVecLength(Float:v1x, Float:v1y, Float:v1z); // calculates length of a simple XYZ 3d vector (FAST,less precision)
native Float:MPClamp360(Float:value);
native Float:MPDistance(Float:v1x, Float:v1y, Float:v1z, Float:v2x, Float:v2y, Float:v2z);  // distance between 2 points
native Float:MPDistancePointLine(Float:PointX, Float:PointY, Float:PointZ, Float:LineSx, Float:LineSy, Float:LineSz, Float:LineEx, Float:LineEy, Float:LineEz); // [url]http://paulbourke.net/geometry/pointline/[/url] returns super huge number 10000000 if outside of range of specified the lie segment.
native Float:MPDotProduct(Float:v1x, Float:v1y, Float:v1z, Float:v2x, Float:v2y, Float:v2z);
native Float:MPFDistance(Float:v1x, Float:v1y, Float:v1z, Float:v2x, Float:v2y, Float:v2z); // distance between 2 points (faster but less precise)
native Float:MPFSQRT(Float:value);  // Faster sqrt (google the 0x5f3759df method)
native Float:MPVecLength(Float:v1x, Float:v1y, Float:v1z); // calculates length of a simple XYZ 3d vector
native MPCrossProduct(Float:v1x, Float:v1y, Float:v1z, Float:v2x, Float:v2y, Float:v2z, &Float:resx, &Float:resy, &Float:resz);
native MPFNormalize(&Float:vx, &Float:vy, &Float:vz); // fast float normalization of a vector to unit-length (makes whatever vector 1.0 long, purely to preserve direction and be able to scale it controllably)
native MPInterpolatePoint(Float:v1x, Float:v1y, Float:v1z, Float:v2x, Float:v2y, Float:v2z, &Float:resx, &Float:resy, &Float:resz, Float:distance);