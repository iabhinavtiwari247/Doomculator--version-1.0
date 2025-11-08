// Doomculator - core Doomsday logic in JavaScript
const Doomsday = (function(){
  const dayNames = ["Sunday","Monday","Tuesday","Wednesday","Thursday","Friday","Saturday"];

  function isLeapYear(year){
    return (year % 4 === 0 && year % 100 !== 0) || (year % 400 === 0);
  }

  function getCenturyAnchor(year){
    const century = Math.floor(year / 100);
    return (5 * (century % 4) + 2) % 7; // Conway formula
  }

  function calculateYearDoomsday(year){
    const y = year % 100;
    const a = Math.floor(y / 12);
    const b = y % 12;
    const c = Math.floor(b / 4);
    const anchor = getCenturyAnchor(year);
    return (a + b + c + anchor) % 7;
  }

  const monthDoomsdays = [0,3,28,14,4,9,6,11,8,5,10,7,12]; // 1-based

  function getMonthDoomsday(month, leap){
    if(month === 1) return leap ? 4 : 3;
    if(month === 2) return leap ? 29 : 28;
    return monthDoomsdays[month];
  }

  function getDayOfWeek(day, month, year){
    // validate
    if(typeof day !== 'number' || typeof month !== 'number' || typeof year !== 'number') throw new Error('Invalid inputs');
    if(month < 1 || month > 12) throw new Error('Invalid month');
    const daysInMonth = new Date(year, month, 0).getDate();
    if(day < 1 || day > daysInMonth) throw new Error('Invalid day for month');

    const leap = isLeapYear(year);
    const yearDoomsday = calculateYearDoomsday(year);
    const monthDoomsday = getMonthDoomsday(month, leap);
    let diff = (day - monthDoomsday) % 7;
    if(diff < 0) diff += 7;
    const target = (yearDoomsday + diff) % 7;
    return { index: target, name: dayNames[target] };
  }

  function addDays(day, month, year, offset){
    const dt = new Date(year, month - 1, day);
    dt.setDate(dt.getDate() + offset);
    return { day: dt.getDate(), month: dt.getMonth() + 1, year: dt.getFullYear() };
  }

  function dateDifference(d1,m1,y1, d2,m2,y2){
    const a = new Date(y1, m1-1, d1);
    const b = new Date(y2, m2-1, d2);
    const diffMs = b - a;
    const days = Math.round(diffMs / (1000*60*60*24));
    return days;
  }

  return { isLeapYear, getDayOfWeek, addDays, dateDifference };
})();

// UI hookup
document.addEventListener('DOMContentLoaded', ()=>{
  const el = id => document.getElementById(id);

  el('btn-day').addEventListener('click', ()=>{
    try{
      const day = Number(el('d1').value);
      const month = Number(el('m1').value);
      const year = Number(el('y1').value);
      const res = Doomsday.getDayOfWeek(day, month, year);
      el('day-result').textContent = `${day}/${month}/${year} → ${res.name}`;
    }catch(e){ el('day-result').textContent = 'Error: ' + e.message }
  });

  el('btn-add').addEventListener('click', ()=>{
    try{
      const day = Number(el('d2').value);
      const month = Number(el('m2').value);
      const year = Number(el('y2').value);
      const offset = Number(el('daysToAdd').value);
      const r = Doomsday.addDays(day, month, year, offset);
      const dow = Doomsday.getDayOfWeek(r.day, r.month, r.year);
      el('add-result').textContent = `${offset>=0?'+':''}${offset} days → ${r.day}/${r.month}/${r.year} (${dow.name})`;
    }catch(e){ el('add-result').textContent = 'Error: ' + e.message }
  });

  el('btn-diff').addEventListener('click', ()=>{
    try{
      const d1 = Number(el('a1').value); const m1 = Number(el('a2').value); const y1 = Number(el('a3').value);
      const d2 = Number(el('b1').value); const m2 = Number(el('b2').value); const y2 = Number(el('b3').value);
      const days = Doomsday.dateDifference(d1,m1,y1, d2,m2,y2);
      el('diff-result').textContent = `${days} day(s) between ${d1}/${m1}/${y1} and ${d2}/${m2}/${y2}`;
    }catch(e){ el('diff-result').textContent = 'Error: ' + e.message }
  });
});