// get all thumbnail images
const thumbnails = document.querySelectorAll('.thumbnail');

// loop through each thumbnail and attach a mouseover event listener
thumbnails.forEach(thumbnail => {
  thumbnail.addEventListener('mouseover', () => {
    // get the full image url from the data attribute
    const fullImageUrl = thumbnail.getAttribute('data-full-image');

    // set the full image source to the url of the thumbnail's data attribute
    const fullImage = document.querySelector('#full-image');
    fullImage.setAttribute('src', fullImageUrl);
  });

  thumbnail.addEventListener('mouseout', () => {
    // clear the full image source when the user stops hovering over a thumbnail
    const fullImage = document.querySelector('#full-image');
    fullImage.setAttribute('src', '');
  });
});

