import { TestBed } from '@angular/core/testing';

import { servizioTest } from './test-service.service';

describe('TestServiceService', () => {
  let service: servizioTest;

  beforeEach(() => {
    TestBed.configureTestingModule({});
    service = TestBed.inject(servizioTest);
  });

  it('should be created', () => {
    expect(service).toBeTruthy();
  });
});
