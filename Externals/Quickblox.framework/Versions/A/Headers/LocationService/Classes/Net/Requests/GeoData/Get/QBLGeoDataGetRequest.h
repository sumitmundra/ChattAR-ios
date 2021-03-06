//
//  QBLGeoDataGetRequest.h
//  LocationService
//

//  Copyright 2011 QuickBlox team. All rights reserved.
//

#import <Foundation/Foundation.h>

@class QBLGeoData;

/** QBLGeoDataGetRequest class declaration. */
/** Overview */
/** This class represent an instance of request for get multiple geodata. */

@interface QBLGeoDataGetRequest : PagedRequest {
	// Filters
	NSDate *createdAt;
	NSUInteger userID;
	NSString *userName;
	
	// Diapazones
	NSDate *minCreatedAt;
	NSDate *maxCreatedAt;
	struct QBLGeoDataRect geoRect;
	NSInteger radius;
	
	// Sorting
	BOOL sortAsc;
	enum QBLGeoDataSortByKind sortBy;
	
	// Special
	BOOL lastOnly;
    BOOL status;
	CLLocationCoordinate2D currentPosition;
}


#pragma mark -
#pragma mark Filters

/** Time of created instance of geodata. When specified, it will return only instances created at 'created_at' time. Type: Unix timestamp. Value example: 1326471371. */
@property (nonatomic, retain) NSDate *createdAt;

/** User id. When specified, it will return only the instances created by QBUUser with id = userID. */
@property (nonatomic) NSUInteger userID;

/** Substring. Search for API Users full_name and login fields. When specified, it will return only the instances created by API Users who have in login or full_name passed substring.*/
@property (nonatomic, retain) NSString *userName;


#pragma mark -
#pragma mark Diapazones

/** Min value of created_at. If this parameter is specified, must return instances with created_at greater than or equal to a given value. Type: Unix timestamp. Value example: 1326471371. */
@property (nonatomic, retain) NSDate *minCreatedAt;

/** Max value of created_at. If this parameter is specified, must return instances with created_at less than or equal to a given value. Type: Unix timestamp. Value example: 1326471371. */
@property (nonatomic, retain) NSDate *maxCreatedAt;

/** If this parameter is correct, must return instances with coordinates that fall within the rectangle and its border. You need two points to build a rectangle (first point -- South West, second -- North East).*/
@property (nonatomic) struct QBLGeoDataRect geoRect;

/** With 'current_position' describes GeoCircle - "circle" on the earth's surface, given the coordinates 'current_position' and this distance in meters ('radius'). */
@property (nonatomic) NSInteger radius;


#pragma mark -
#pragma mark Sorting

/** Indicates that the sorting should be by ascending. If this parameter is not set - the sort is by descending. Value example: 1 (all other values ​​as well as the presence of this key parameter without 'sort_by' ​​cause an error validation). */
@property (nonatomic) BOOL sortAsc;

/** Kind of sort. Posible values presented in QBGeoDataSortByKind enum. */
@property (nonatomic) enum QBLGeoDataSortByKind sortBy;


#pragma mark -
#pragma mark Special

/** The result will only include the last time data. For example, if the query is filtered by userID parameter and flag last_only is set, we get an instance - the most recent by created_at for this user, its last known position. Value example: 1 (all other values ​​cause an error validation). */
@property (nonatomic) BOOL lastOnly;

/** The result will only include instances that have a non-empty 'status' field. Value example: 1 (all other values ​​cause an error validation). */
@property (nonatomic) BOOL status;

/** The current position of the user. Used only in conjunction with the keys 'radius' and 'distance'. If this option is specified, and it does not set any of these parameters - error validation. Use '%3B' instead ';'. Value example: 1%3B2.*/
@property (nonatomic) CLLocationCoordinate2D currentPosition;

@end