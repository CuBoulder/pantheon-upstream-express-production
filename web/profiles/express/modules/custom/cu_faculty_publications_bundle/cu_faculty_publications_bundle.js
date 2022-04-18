const allAuthors = document.querySelectorAll('.all-authors');

allAuthors.forEach(detailsElement => {
  detailsElement.addEventListener('toggle', event => {
    console.log(event.target);
    event.target.firstElementChild.firstElementChild.toggleAttribute('hidden');
  });
});
