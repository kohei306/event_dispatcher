





<!-- ABOUT THE PROJECT -->
## Light weight Event dispatcher with strict type check.

1.Create Event type definition and Event type - EventDataType Mapping
   E.g. CREATE_EVENT_DATA_MAP(VelocityDataUpdate, float)

   1.a Subscribe to the Event with callback function which has the corresponding EventDataType as an argument (const EventDataType &)
     E.g. void CallBackVelocity(const float & velocity);    
     event_dispatcher::SubscribeToEvent<event_dispatcher::VehicleStateDataUpdateEvent>(&ComponentB::CallBackVelocity, this);

   1.b Publish to the Event with the corresponding EventDataType
     E.g. float velocity; 
     event_dispatcher::PublishEvent<event_dispatcher::VehicleStateDataUpdateEvent>(velocity);

 See the ComponentA/B/C example in test for more information.

 

