#what to account for when making the schedule
does the time fit in their normal availability
have they asked off for that date
maximum hours they can work
minimum hours they have to work
current hours worked
have they passed the min threshold
how close are they to the maximum hours compared to other employees that can fill that position
do they pass the competency threshold (subject to removal)
are all necessary positions filled (headBar, door, bottle, etc.)
how many slots need to be filled for a given time
what degree of busy template should be used this week
if they closed the previous night are they ok with opening again the next day

#steps the program should take when making the schedule
    the scheduler will make an entire days schedule then move to the next day

1. look at the date, ignore any employee that asked off for that date
2. if it's an opener shift, check if they're ok with opening if they closed the previous night
3. check if they worked that day already or not
4. look at the necessary positions, for each time slot starting in the morning going until evening
    ignore all employees that don't qualify for the given position
    ignore all employees that aren't available for that time slot
    check current hours worked of remaining employees to ensure they've met minimum hours
    check current hours to ensure the wont go over 40 hours
!!!   compare possible employees to see who needs more hours by:
        checking how close they are to minimum hours for each
        if the day is marked as busy, implement competency scores
        if all employees are past minimum threshold, give shift to employee that has fewest hours and meets requirements

#employee competency testing
rank competency from 1-10
above 5 means they can handle a crowd
above 7 means they can open/close alone

#reminders
new employee page is functional
edit employee page is functional
show employee page is functional aside from hour tracker
asking for vacation is functional except for not being able to remove an added date without reloading page and it errors if no date is asked off

this is only half working, changing the dropdown still doesnt uncheck boxes
    when selecting un/full available, clear dropdowns AND when selecting dropdown value, clear un/full available
        convert the checkboxes to radio buttons when this is implemented

find a calendar API to fill in the vacation piece of employee data and keep track of dates for the schedule

remake day model and have "degree of busy" property that will change from the dropdowns already made
    day model will have empty time properties that the logic that decides who is working will push info to
        then when generating the schedule these objects will be used to update the interface





#google api credentials
client ID: 1025857696026-8so8ns1aq30murejj60cragdjlvcua4f.apps.googleusercontent.com
client secret: DwbcnX8ED-AS5qAtu6a7Gdg3

<%for (let prop in employees){%>
    <%if(employees.hasOwnProperty(prop)){%>
        <li><%= prop %></li>
    <%}%>
<%}%>

<%for (let emp in employees){%>
    <% console.log(employees[emp].name) %>
<%}%>


<!-- variables for day logic -->
<% let weekObject = weeks[0]._doc; %> 
<% let weekObjKeys = Object.keys(weekObject); %>
<% let weekDays = ['monday', 'tuesday', 'wednesday', 'thursday']; %>
<% let weekendDays = ['friday', 'saturday', 'sunday']; %>
<% let dayArray=[];%>
<!-- loop that designates what days are busy and what to do with a busy/standard day -->
<% for(let prop=1; prop<weekObjKeys.length-1; prop++){ %>
    <!-- if statement to split weekdays vs weekends -->
    <% if(weekDays.includes(weekObjKeys[prop])) { %>
        <!-- if statement to tell the schedule what to do on a busy/standard week day -->
        <% if(weekObject[weekObjKeys[prop]]==="0") { %>
            <% console.log(weekObjKeys[prop] + ' is a normal day'); %>
        <% } else { %>
            <% console.log(weekObjKeys[prop] + ' is a busy day'); %>
        <% } %>     
    <% } else { %>
        <!-- if statement to tell the schedule what to do on a busy/standard/brunch weekend day -->
        <% if(weekObject[weekObjKeys[prop]]==="0") { %>
            <% console.log(weekObjKeys[prop] + ' is a normal day'); %>
        <% } else if(weekObject[weekObjKeys[prop]]==="1") { %>
            <% console.log(weekObjKeys[prop] + ' is a busy day'); %>
        <% } else { %>
            <% console.log(weekObjKeys[prop] + ' is a brunch day'); %>
        <% } %> 
    <% } %>
<% } %>


&& weekObject[weekObjKeys[prop]].degOfBusy=='0'

<!-- variables for day logic -->
<% let weekObject = weeks[0]._doc; %> <!--this actually has all the property information-->
<% let weekObjKeys = Object.keys(weekObject); %> <!--this grabs all the names of the properties -->
<% let weekDays = ['monday', 'tuesday', 'wednesday', 'thursday']; %>
<% let weekendDays = ['friday', 'saturday', 'sunday']; %>
<% let dayArray=[];%>
<!-- loop that designates what days are busy and what to do with a busy/standard day -->

<% for(let prop=0; prop<weekObjKeys.length-2; prop++){ %>
        <% if(weekDays.includes(weekObjKeys[prop]) && weekObject[weekObjKeys[prop]].degOfBusy==='0') { %>
            <p><%= weekObjKeys[prop] %> is a standard day</p>
        <% } %>
    <% } %>